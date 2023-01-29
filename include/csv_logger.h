/**
 *
 * @brief - implements CSV Logger
 *
 * @copyright - 2020-present (devnaga@tuta.io) Devendra Naga
 */
#ifndef __AUTO_LIB_CSV_LOGGER_H__
#define __AUTO_LIB_CSV_LOGGER_H__

namespace auto_os::lib {

class csv_logger {
    public:
        explicit csv_logger(const std::string name, const std::string mode, bool header);
        ~csv_logger();

        int read_record(std::vector<std::string> &records);
        int write_record(std::vector<std::string> records);
        int flush();

    private:
        FILE *csv_fp_;
        bool file_in_read_;
};

}

#endif


