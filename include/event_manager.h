/**
 * @brief - implements event manager in C++
 *
 * @copyright 2019-present Devendra Naga (devnaga@tuta.io) All rights reserved
 */

#ifndef __AUTO_LIB_EVENT_MANAGER_H__
#define __AUTO_LIB_EVENT_MANAGER_H__

#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <thread>
#include <mutex>
#include <functional>
#include <queue>
#include <condition_variable>
#include <sys/select.h>

#include <logger.h>

namespace auto_os::lib {

// timer callback
typedef std::function<void(void)> timer_fn;

// socket callback
typedef std::function<void(int)> socket_fn;

// signal callback
typedef std::function<void(int)> signal_fn;

// job callback
typedef std::function<void(void)> job_fn;

/*
 * @brief - a process that is instantiated by the Parallel
 */
class thread_worker {
    public:
        explicit thread_worker();
        ~thread_worker();

        void queue_work(job_fn job);
        void stop();

    private:
        void process();
        std::unique_ptr<std::thread> proc_;
        std::queue<job_fn> jobs_;
        std::mutex lock_;
        std::condition_variable cv_;
        bool stop_signal_ = false;
};

/**
 * @brief - implements threadpool design pattern
 */
class thread_pool {
    public:
        explicit thread_pool();
        ~thread_pool();

        void queue_work(job_fn job);
        void stopall();
    private:
        std::vector<std::shared_ptr<thread_worker>> procs_;
        int n_threads_;
};

/**
 * @brief - implements event_manager timer
 */
struct event_manager_timer {
    int sec_;
    int usec_;
    int fd_;
    bool oneshot_;
    bool complete_;
    timer_fn timer_fn_;
};

/**
 * @brief - implements event_manager socket
 */
struct event_manager_socket {
    int fd_;
    socket_fn socket_fn_;
};

/**
 * @brief - implements event_manager signal
 */
struct event_manager_signal {
    uint32_t sig;
    std::vector<signal_fn> signal_fn_;
};

struct deadline_context {
    int deadline_msec;
    timer_fn timer_fn_;
    socket_fn sock_fn_;
};

// Grand Central Dispatch main class
class event_manager {
    public:
        static event_manager *instance()
        {
            static event_manager em;

            return &em;
        }

        /**
         * @brief - set logger instance
         */
        void set_logger(std::shared_ptr<auto_os::lib::logger> log)
        {
            log_ = log;
        }

        event_manager(const event_manager &) = delete;
        const event_manager &operator=(const event_manager &) = delete;
        event_manager(const event_manager &&) = delete;
        const event_manager &&operator=(const event_manager &&) = delete;

        ~event_manager();

        // create timer event with sec, usec and a callback
        int create_timer_event(int sec, int usec, timer_fn ti_fn) noexcept;

        // create oneshot timer event with sec, usec and a callback
        int create_timer_event(bool oneshot, int sec, int usec, timer_fn ti_fn) noexcept;

        // delete oneshot timer event if no longer required
        int delete_timer_event(timer_fn ti_fn) noexcept;

        // create socket event with fd and a callback
        int create_socket_event(int fd, socket_fn s_fn) noexcept;

        // delete socket event if closed / not need to listen to it any longer
        int delete_socket_event(int fd) noexcept;

        // create signal event with signal no and a callback
        int create_signal_event(uint32_t sig, signal_fn s_fn) noexcept;

        int register_term_signals(signal_fn s_fn) noexcept;

        // run an execution context
        void run_execution(job_fn job) noexcept;

        // run the main event manager
        void start() noexcept;

        /**
         * @brief - terminate the Event Loop wheel
         *
         * @return void
         */
        inline void terminate() { terminate_ = true; }
    private:

        // logging instance pointer
        std::shared_ptr<auto_os::lib::logger> log_;

        // list of timers
        std::vector<event_manager_timer> timers_;

        // list of sockets
        std::vector<event_manager_socket> sockets_;

        // list of signals
        std::vector<event_manager_signal> signals_;

        std::vector<deadline_context> deadline_ctx_;

        // parallel context
        std::unique_ptr<thread_pool> p_;

        // set to true when Terminate() is called
        bool terminate_ = false;

        // fd to handle the signals
        int signal_fd_;

        // maks of all the signals
        sigset_t signal_masks_;

        // maks of all the fds
        fd_set allfd_;

        std::unique_ptr<std::thread> deadline_thr_;

        // get allmax fds
        int get_max_fd_();

        void deadline_check();

        // priovate constructor .. base singleton
        explicit event_manager();
};

}

#endif


