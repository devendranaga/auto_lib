/**
 * @brief - Implements signal interface.
 *
 * @author - Devendra Naga (devendra.aaru@outlook.com).
 * @copyright - 2022-present All rights reserved.
 */
#ifndef __AUTO_LIB_SIGNAL_INTF_H__
#define __AUTO_LIB_SIGNAL_INTF_H__

namespace auto_os::lib {

/**
 * @brief - Block signals.
 *
 * @param in signals - List of signals to block.
 *
 * @return 0 on success -1 on failure.
 */
int block_signals(std::vector<int> signals);

/**
 * @brief - Block termination signals (SIGINT, SIGTERM).
 *
 * @return 0 on success -1 on failure.
 */
int block_term_signals(void);

}

#endif

