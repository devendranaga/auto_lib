/**
 * @brief - Implements pid file.
 *
 * @author Devendra Naga (devendra.aaru@outlook.com).
 * @copyright 2022-present All rights reserved.
 */
#ifndef __AUTO_LIB_PID_FILE_H__
#define __AUTO_LIB_PID_FILE_H__

namespace auto_os::lib {

class pid_file {
    public:
        explicit pid_file() = default;
        ~pid_file() = default;

        /**
         * @brief - creates a pid file.
         *
         * @param[in] filename - pid filename.
         *
         * @return 0 on success -1 on failure.
         */
        int create_pidfile(std::string &filename);

        /**
         * @brief - delete the pid file.
         *
         * @param[in] filename - pid filename.
         */
        void delete_pidfile(std::string &filename);
};

}

#endif

