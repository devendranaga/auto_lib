/**
 * 
 * @brief - implements cpu info
 * 
 * @author - Devendra Naga (devendra.aaru@outlook.com)
 * @copyright - 2021-present All rights reserved
 */
#ifndef __AUTO_LIB_CPU_INFO_H__
#define __AUTO_LIB_CPU_INFO_H__

#include <logger.h>

namespace auto_os::lib {

struct cpu_info_x86 {
    int                         processor;
    std::string                 vendor_id;
    int                         cpu_family;
    int                         model;
    std::string                 model_name;
    int                         stepping;
    std::string                 microcode;
    double                      cpu_mhz;
    double                      cache_size;
    int                         physical_id;
    int                         siblings;
    int                         core_id;
    int                         cpu_cores;
    int                         apicid;
    int                         initial_apicid;
    bool                        fpu;
    bool                        fpu_exception;
    int                         cpuid_level;
    bool                        wp;
    std::vector<std::string>    flags;
    std::vector<std::string>    bugs;
    double                      bogomips;
    int                         clflush_size;
    int                         cache_alignment;
    std::string                 address_sizes;
    std::string                 power_mgmt;
};

struct cpu_info_rpi3 {
};

struct cpu_info_rpi4_cpu {
    int processor;
    bool has_processor;
    double bogomips;
    bool has_bogomips;
    std::vector<std::string> features;
    bool has_features;
    int cpu_implementer;
    bool has_cpu_implementer;
    int cpu_architecture;
    bool has_cpu_architecture;
    int cpu_variant;
    bool has_cpu_variant;
    int cpu_part;
    bool has_cpu_part;
    int cpu_revision;
    bool has_cpu_revision;

    void initialize()
    {
        has_processor =
        has_bogomips =
        has_features =
        has_cpu_implementer =
        has_cpu_architecture =
        has_cpu_variant =
        has_cpu_part =
        has_cpu_revision = false;
        (void)features.empty();
    }

    inline void print(std::shared_ptr<auto_os::lib::logger> &log)
    {
        log->debug("\tcpu: {\n");
        log->debug("\t\t processor: %d\n", processor);
        log->debug("\t\t bogomips: %f\n", bogomips);
        log->debug("\t\t features: ");
        for (auto it : features) {
            fprintf(stderr, "%s ", it.c_str());
        }
        fprintf(stderr, "\n");
        log->debug("\t\t cpu_implementer: 0x%x\n", cpu_implementer);
        log->debug("\t\t cpu_architecture: %d\n", cpu_architecture);
        log->debug("\t\t cpu_variant: %d\n", cpu_variant);
        log->debug("\t\t cpu_part: %d\n", cpu_part);
        log->debug("\t\t cpu_revision: %d\n", cpu_revision);
        log->debug("\t}\n");
    }
};

/**
 * @brief - RPI4 cpuinfo
 */
struct cpu_info_rpi4 {
    // per cpu core info
    std::vector<cpu_info_rpi4_cpu> cpu;
    std::string hardware;
    std::string revision;
    std::string serial;
    std::string model;

    /**
     * @brief - print cpu info
     * 
     * @param log - logger config instance
     */
    inline void print(std::shared_ptr<auto_os::lib::logger> &log)
    {
        log->debug("rpi4_cpu: {\n");
        for (auto it : cpu) {
            it.print(log);
        }
        log->debug("\t hardware: %s\n", hardware.c_str());
        log->debug("\t revision: %s\n", revision.c_str());
        log->debug("\t serial: %s\n", serial.c_str());
        log->debug("\t model: %s\n", model.c_str());
        log->debug("}\n");
    }
};

struct cpu_info_nvidia_jetson_nano_item {
    int processor;
    bool has_processor;
    std::string model_name;
    bool has_model_name;
    double bogomips;
    bool has_bogomips;
    std::vector<std::string> features;
    bool has_features;
    uint32_t cpu_implementer;
    bool has_cpu_implementer;
    int cpu_architecture;
    bool has_cpu_architecture;
    int cpu_variant;
    bool has_cpu_variant;
    int cpu_part;
    bool has_cpu_part;
    int cpu_revision;
    bool has_cpu_revision;

    inline void initialize()
    {
        has_processor =
        has_model_name =
        has_bogomips =
        has_features =
        has_cpu_implementer =
        has_cpu_architecture =
        has_cpu_variant =
        has_cpu_part =
        has_cpu_revision = false;
        features.clear();
    }

    inline void print(std::shared_ptr<auto_os::lib::logger> &log)
    {
        log->debug("\t cpuinfo: {\n");
        log->debug("\t\t processor: %d\n", processor);
        log->debug("\t\t model_name: %s\n", model_name.c_str());
        log->debug("\t\t bogomips: %f\n", bogomips);
        log->debug("\t\t features:\n");
        for (auto feature : features) {
            log->debug("\t\t\t %s\n", feature.c_str());
        }
        log->debug("\t\t cpu_implementer: %d\n", cpu_implementer);
        log->debug("\t\t cpu_architecture: %d\n", cpu_architecture);
        log->debug("\t\t cpu_variant: %d\n", cpu_variant);
        log->debug("\t\t cpu_part: %d\n", cpu_part);
        log->debug("\t\t cpu_revision: %d\n", cpu_revision);
        log->debug("\t }\n");
    }
};


struct cpu_info_nvidia_jetson_nano {
    std::vector<cpu_info_nvidia_jetson_nano_item> items;
    inline void print(std::shared_ptr<auto_os::lib::logger> &log)
    {
        log->debug("nvidia cpu: {\n");
        for (auto it : items) {
            it.print(log);
        }
        log->debug("}\n");
    }
};

/**
 * @brief - implements naonpi_neo cpu info
 */
struct cpu_info_nanopi_neo_info {
    int                             processor;
    bool                            processor_avail;
    std::string                     model_name;
    bool                            model_name_avail;
    double                          bogomips;
    bool                            bogomips_avail;
    std::vector<std::string>        features;
    std::string                     cpu_impl;
    bool                            cpu_impl_avail;
    int                             cpu_arch;
    bool                            cpu_arch_avail;
    std::string                     cpu_variant;
    bool                            cpu_variant_avail;
    std::string                     cpu_part;
    bool                            cpu_part_avail;
    int                             cpu_revision;
    bool                            cpu_revision_avail;

    void initialize()
    {
        processor           = 0;
        bogomips            = 0;
        cpu_arch            = 0;
        cpu_revision        = 0;
        processor_avail     = false;
        model_name_avail    = false;
        bogomips_avail      = false;
        cpu_impl_avail      = false;
        cpu_arch_avail      = false;
        cpu_variant_avail   = false;
        cpu_part_avail      = false;
        cpu_revision_avail  = false;
        features.clear();
        cpu_impl            = "";
        cpu_variant         = "";
        cpu_part            = "";
    }

    void print(std::shared_ptr<auto_os::lib::logger> &log)
    {
        log->debug("\t cpuinfo: {\n");
        log->debug("\t\t processor: %d\n", processor);
        log->debug("\t\t model_name: %s\n", model_name.c_str());
        log->debug("\t\t bogomips: %f\n", bogomips);
        log->debug("\t\t features: [ ");
        for (auto it : features) {
            printf(" %s", it.c_str());
        }
        printf(" ]\n");
        log->debug("\t\t cpu_impl: %s\n", cpu_impl.c_str());
        log->debug("\t\t cpu_arch: %d\n", cpu_arch);
        log->debug("\t\t cpu_variant: %s\n", cpu_variant.c_str());
        log->debug("\t\t cpu_part: %s\n", cpu_part.c_str());
        log->debug("\t\t cpu_revision: %d\n", cpu_revision);
        log->debug("\t }\n");
    }
};

struct cpu_info_nanopi_neo {
    std::vector<cpu_info_nanopi_neo_info> items;
    std::string hardware;
    std::string revision;
    std::string serial;

    void print(std::shared_ptr<auto_os::lib::logger> &log)
    {
        log->debug("nanopi_neo: {\n");
        for (auto it : items) {
            it.print(log);
        }
        log->debug("\t hardware: %s\n", hardware.c_str());
        log->debug("\t revision: %s\n", revision.c_str());
        log->debug("\t serial: %s\n", serial.c_str());
        log->debug("}\n");
    }
};

// for linux based systems
const std::string cpuinfo_file = "/proc/cpuinfo";

class cpu_info {
    public:
        /**
         * @brief - get cpu info
         */
        explicit cpu_info(cpu_info_x86 &x86);
        explicit cpu_info(cpu_info_rpi3 &rpi3);
        explicit cpu_info(cpu_info_rpi4 &rpi4);
        explicit cpu_info(cpu_info_nvidia_jetson_nano &nv_jetson);
        explicit cpu_info(cpu_info_nanopi_neo &nanopi_neo);
        ~cpu_info();
};

}

#endif


