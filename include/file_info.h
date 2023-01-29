/**
 * @brief - implements file_info utility functions
 *
 * @author - Devendra Naga (devendra.aaru@outlook.com)
 * @copyright - 2021-present All rights reserved
 */
#ifndef __AUTO_LIB_FILE_INFO_H__
#define __AUTO_LIB_FILE_INFO_H__

#include <vector>
#include <time_date.h>
#include <auto_os_errors.h>

namespace auto_os::lib {


/**
 * @brief - file types
 */
enum class file_type {
    eregular = 1,
    edirectory,
    efifo,
    echrdev,
    epipe,
    esocket,
    eblkdev,
    eunknown,
};

enum class module_state {
    Live,
    Loading,
    Unloading,
};

/**
 * @brief - file description
 */
struct file_description {
    file_type       type;
    std::string     filename;
};

struct module_info {
    std::string module_name;
    uint32_t memory_size_bytes;
    int instances;
    std::vector<std::string> dependencies;
    module_state state;
    uint32_t memory_offset;
};

/**
 * @brief - get open file descriptors and their absolute paths
 * 
 */
class proc_file_info {
    public:
        explicit proc_file_info() = default;
        ~proc_file_info() = default;

        /**
         * @brief Get the open files given the pid
         * 
         * @param out file_list - list of files
         * @param in pid - pid of the process to get open files
         * @return 0 on success -1 on failure
         */
        int get_open_files(std::vector<std::string> &file_list, uint32_t pid);
        int get_loaded_modules(std::vector<module_info> &mod_set);

        /**
         * @brief Get the hostname for linux
         * 
         * @param out hostname  - Hostname
         *
         * @return return ERROR_NO_ERROR on success
         * @return return ERROR_PROC_HOSTNAME_OPEN_FAILURE on failure
         */
        auto_os::errors::error_type
        get_hostname(std::string &hostname);

        auto_os::errors::error_type
        set_hostname(const std::string &hostname);
};

/**
 * @brief - file permission types
 */
struct file_perm_types {
    bool user_read;
    bool user_write;
    bool user_exec;
    bool group_read;
    bool group_write;
    bool group_exec;
    bool other_read;
    bool other_write;
    bool other_exec;

    /**
     * @brief - set default values
     */
    explicit file_perm_types()
    {
        user_read   =
        user_write  =
        group_read  =
        group_write = true;

        user_exec   =
        group_exec  =
        other_read  =
        other_write =
        other_exec  = false;
    }

    ~file_perm_types() = default;
};

/**
 * @brief - file permissions
 */
class file_permissions {
    public:
        explicit file_permissions() = default;
        ~file_permissions() = default;

        /**
         * @brief - set permissions
         *
         * @param in filename - filename to set permissions
         * @param in types - file permissions
         *
         * @return 0 on success -1 on failure
         */
        int set_permissions(const std::string &filename, const file_perm_types &types);

        /**
         * @brief - get permissions
         *
         * @param in filename - filename to get permissions
         * @param in types - file permissions
         *
         * @return 0 on success -1 on failure
         */
        int get_permissions(const std::string &filename, file_perm_types &types);
};

/**
 * @brief - fileinfo utilities
 */
class fileinfo_utils {
    public:
        ~fileinfo_utils() = default;
        fileinfo_utils(const fileinfo_utils &) = delete;
        const fileinfo_utils &operator=(const fileinfo_utils &) = delete;
        fileinfo_utils(const fileinfo_utils &&) = delete;
        const fileinfo_utils &&operator=(const fileinfo_utils &&) = delete;

        /**
         * @brief - get an instance of the class
         *
         * @return pointer to fileinfo_utils
         */
        static fileinfo_utils *instance() {
            static fileinfo_utils utils;
            return &utils;
        }

        /**
         * @brief - unlink file
         *
         * @param in filename - filename
         *
         * @return 0 on success -1 on failure
         */
        int unlink_file(const std::string &filename);
    private:
        explicit fileinfo_utils() = default;
};

/**
 * @brief - implements file_info class definition
 */
class file_info {
    public:
        explicit file_info() = default;
        ~file_info() = default;

        /**
         * @brief - Check if file is accessible.
         *
         * @param in filename - name of the file.
         *
         * @return 0 on success -1 on failure.
         */
        int is_file_accessible(const std::string &filename);

        /**
         * @brief - Get file size in bytes.
         * 
         * @param[in] filename - filename.
         * @param[inout] file_size - returned filesize in bytes.
         * 
         * @return 0 on success -1 on failure.
         */
        int get_file_size_bytes(const std::string &filename, size_t &file_size);

        /**
         * @brief - Get file access timestamp.
         * 
         * @param[in] filename - filename.
         * @param[inout] last_mod - last modification time.
         * @param[inout] last_acc - last accessed time.
         * @param[inout] last_status_change - last status change time.
         * 
         * @return 0 on success -1 on failure.
         */
        int get_file_access_timestamp(const std::string &filename,
                                timestamp &last_mod,
                                timestamp &last_acc,
                                timestamp &last_status_change);

        /**
         * @brief - Get file type.
         * 
         * @param[in] filename - filename.
         * 
         * @return returns file_type on success file_type::eunknown on failure.
         */
        file_type get_file_type(const std::string &filename);

        /**
         * @brief - get absolute filename from a symlink
         *
         * @param[in] name - input symlink file
         * @param[inout] realname - realname of the file after reading symlink
         *
         * @return 0 on success -1 on failure
         */
        int get_absolute_filename(const std::string name, std::string &realname);

        /**
         * @brief - Get file type string.
         * 
         * @param[in] type - file type
         * 
         * @return returns file_type in string format.
        */
        std::string file_type_str(file_type type);
};

/**
 * @brief - directory content information
 */
struct directory_content {
    std::string filename;
    file_type type;
    size_t file_size;
    timestamp last_mod;
    timestamp last_acc;
    timestamp last_status_change;
};

/**
 * @brief - implements directory_info
 */
class directory_info {
    public:
        explicit directory_info() = default;
        ~directory_info() = default;

        /**
         * @brief - imeplements create directory
         *
         * @param in dir - directory
         *
         * @return 0 on success -1 on failure
         */
        int create_directory(const std::string &path);

        /**
         * @brief - imeplements read directory
         *
         * @param in dir - directory
         * @param in content - list of directory contents
         *
         * @return 0 on success -1 on failure
         */
        int read_directory(const std::string &dir, std::vector<directory_content> &content);

        /**
         * @brief - find file in the given directory input
         *
         * @param in dir - directory
         * @param in filename - filename
         * @param in is_regular - set if normal file
         *
         * @return true on success -1 on failure
         */
        bool find_file(const std::string &dir, const std::string &filename, bool is_regular = false);
        int find_files_with_extension(const std::string &dir,
                                      const std::string ext,
                                      std::vector<std::string> files);
        int delete_directory(const std::string &path);
};

class disk_info {
    public:
        explicit disk_info() = default;
        ~disk_info() = default;

        int get_disk_usage(const std::string &path, double &disk_use);
        int get_free_usage(const std::string &path, double &disk_free);
};

}

#endif

