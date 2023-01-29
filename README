# Auto Lib

Auto Lib name comes from the time when i wanted to write this library for
automotive area. But over the time this library became too generic that
it can be used in any platform.

Auto Lib is developed to overcome difficulties in the following areas:

1. Capture systemic events such as Timers, Sockets, Signals.
2. Events to be delivered as either callbacks or must be run in worker thread.
3. Abstraction required for system calls and other features exposed in /proc and /sys.
   - No one wants to rewrite a message send and receiver.
   - No one wants to perform system call socket calls / ipc calls.
4. Programmatically modify some of system level features (cpu frequency, scheduling
   parameters) for much finer control.
5. System wide common logger helper that can have various sinks - console, file etc.

Following are currently supported features of Auto Lib.

| S.No | Feature | header | Description |
|------|---------|--------|-------------|
| 1 | Logger | `logger.h` | Log to either console or to a logging daemon |
| 2 | Event manager | `event_manager.h` | Manage and perform callbacks for timers, sockets and signals |
| 3 | Socket api | `socket_api.h` | Socket routines for tcp, udp, unix domain server and clients and raw sockets |
| 4 | Compressor | `compress_factory.h` | Compression / Decompression utility. gz and zstd are supported |
| 5 | Network ioctls | `nw_ctl.h` | Network IOCTLs |
| 6 | Network stats | `net_stats.h` | Network Interface statistics |
| 7 | Serial | `serial_device.h` | Serial device manipulation |
| 8 | Random generation | `random_generator.h` | Random number generation API |
| 9 | Profiling | `perf_profiling.h` | Performance Profiling |
| 10 | Signals | `signal_intf.h` | Control System wide signals and control signal deliveries |
| 11 | File i/o | `file_io.h` | Performs File i/o operations (open, read, write, close) |
| 12 | Pcap control | `pcap_op.h` | Open / Read / Write pcap files |
| 13 | Thermal | `thermal.h`| Get temperature from underlying hardware |
| 14 | CPU usage | `cpu_use.h` | Get the CPU usage |
| 15 | CPU info | `cpu_info.h` | Get the CPU info |
| 16 | CPU Frequency | `cpu_freq.h` | Control the CPU frequency (set / get cpu scaling governors / frequencies) |
| 17 | CAN control | `can_if.h` | CAN network manipulation (open, read, write on CAN devices) |
| 18 | CSV Logging | `csv_logger.h` | CSV Logging utility |
| 19 | File info | `file_info.h` | Get details about files (type, size, creation etc) and directories |
| 20 | LEDs | `leds.h` | Control LEDs on the hardware |
| 21 | Thread control | `thread_intf.h` | Control Scheduling parameters of a thread |

# How to compile

A precompiled library is given for both X86_64 and AARCH64. Below are the steps to compile.

```bash
mkdir build/
cd build/
cmake ..
make -j24
```

# Dependencies

To fully utilize this library, following dependencies must be resolved.

1. libmosquitto and libmosquittopp - for mqtt
2. libpcap - for pcap
3. libcap - for capabilities
4. zlib - for gzip
5. zstd - for zstd

# Binary only Delivery

For the X86_64, the .so files are generated with gcc version 12.2.
For The AARCH64 .so files are generated using `aarch64-buildroot-linux-gnu-gcc` version 11.2 from the buildroot.

Only .so files will be shared. Contact me if you require the copy of the source code.


