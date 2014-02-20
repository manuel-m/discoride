/* Copyright Joyent, Inc. and other Node contributors. All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

TEST_DECLARE   (platform_output)
TEST_DECLARE   (callback_order)
TEST_DECLARE   (close_order)
TEST_DECLARE   (run_once)
TEST_DECLARE   (run_nowait)
TEST_DECLARE   (loop_alive)
TEST_DECLARE   (loop_stop)
TEST_DECLARE   (loop_update_time)
TEST_DECLARE   (barrier_1)
TEST_DECLARE   (barrier_2)
TEST_DECLARE   (barrier_3)
TEST_DECLARE   (condvar_1)
TEST_DECLARE   (condvar_2)
TEST_DECLARE   (condvar_3)
TEST_DECLARE   (condvar_4)
TEST_DECLARE   (condvar_5)
TEST_DECLARE   (semaphore_1)
TEST_DECLARE   (semaphore_2)
TEST_DECLARE   (semaphore_3)
TEST_DECLARE   (tty)
TEST_DECLARE   (stdio_over_pipes)
TEST_DECLARE   (ipc_listen_before_write)
TEST_DECLARE   (ipc_listen_after_write)
#ifndef _WIN32
TEST_DECLARE   (ipc_send_recv_pipe)
#endif
TEST_DECLARE   (ipc_send_recv_tcp)
TEST_DECLARE   (ipc_tcp_connection)
TEST_DECLARE   (tcp_ping_pong)
TEST_DECLARE   (tcp_ping_pong_v6)
TEST_DECLARE   (pipe_ping_pong)
TEST_DECLARE   (delayed_accept)
TEST_DECLARE   (multiple_listen)
TEST_DECLARE   (tcp_writealot)
TEST_DECLARE   (tcp_try_write)
TEST_DECLARE   (tcp_open)
TEST_DECLARE   (tcp_connect_error_after_write)
TEST_DECLARE   (tcp_shutdown_after_write)
TEST_DECLARE   (tcp_bind_error_addrinuse)
TEST_DECLARE   (tcp_bind_error_addrnotavail_1)
TEST_DECLARE   (tcp_bind_error_addrnotavail_2)
TEST_DECLARE   (tcp_bind_error_fault)
TEST_DECLARE   (tcp_bind_error_inval)
TEST_DECLARE   (tcp_bind_localhost_ok)
TEST_DECLARE   (tcp_listen_without_bind)
TEST_DECLARE   (tcp_connect_error_fault)
TEST_DECLARE   (tcp_connect_timeout)
TEST_DECLARE   (tcp_close_while_connecting)
TEST_DECLARE   (tcp_close)
TEST_DECLARE   (tcp_close_accept)
TEST_DECLARE   (tcp_flags)
TEST_DECLARE   (tcp_write_to_half_open_connection)
TEST_DECLARE   (tcp_unexpected_read)
TEST_DECLARE   (tcp_read_stop)
TEST_DECLARE   (tcp_bind6_error_addrinuse)
TEST_DECLARE   (tcp_bind6_error_addrnotavail)
TEST_DECLARE   (tcp_bind6_error_fault)
TEST_DECLARE   (tcp_bind6_error_inval)
TEST_DECLARE   (tcp_bind6_localhost_ok)
TEST_DECLARE   (udp_send_and_recv)
TEST_DECLARE   (udp_multicast_join)
TEST_DECLARE   (udp_multicast_ttl)
TEST_DECLARE   (udp_multicast_interface)
TEST_DECLARE   (udp_dgram_too_big)
TEST_DECLARE   (udp_dual_stack)
TEST_DECLARE   (udp_ipv6_only)
TEST_DECLARE   (udp_options)
TEST_DECLARE   (udp_open)
TEST_DECLARE   (pipe_bind_error_addrinuse)
TEST_DECLARE   (pipe_bind_error_addrnotavail)
TEST_DECLARE   (pipe_bind_error_inval)
TEST_DECLARE   (pipe_listen_without_bind)
TEST_DECLARE   (pipe_connect_bad_name)
TEST_DECLARE   (pipe_connect_to_file)
TEST_DECLARE   (pipe_server_close)
TEST_DECLARE   (connection_fail)
TEST_DECLARE   (connection_fail_doesnt_auto_close)
TEST_DECLARE   (shutdown_close_tcp)
TEST_DECLARE   (shutdown_close_pipe)
TEST_DECLARE   (shutdown_eof)
TEST_DECLARE   (shutdown_twice)
TEST_DECLARE   (callback_stack)
TEST_DECLARE   (error_message)
TEST_DECLARE   (timer)
TEST_DECLARE   (timer_init)
TEST_DECLARE   (timer_again)
TEST_DECLARE   (timer_start_twice)
TEST_DECLARE   (timer_order)
TEST_DECLARE   (timer_huge_timeout)
TEST_DECLARE   (timer_huge_repeat)
TEST_DECLARE   (timer_run_once)
TEST_DECLARE   (timer_from_check)
TEST_DECLARE   (idle_starvation)
TEST_DECLARE   (loop_handles)
TEST_DECLARE   (get_loadavg)
TEST_DECLARE   (walk_handles)
TEST_DECLARE   (watcher_cross_stop)
TEST_DECLARE   (ref)
TEST_DECLARE   (idle_ref)
TEST_DECLARE   (async_ref)
TEST_DECLARE   (prepare_ref)
TEST_DECLARE   (check_ref)
TEST_DECLARE   (unref_in_prepare_cb)
TEST_DECLARE   (timer_ref)
TEST_DECLARE   (timer_ref2)
TEST_DECLARE   (fs_event_ref)
TEST_DECLARE   (fs_poll_ref)
TEST_DECLARE   (tcp_ref)
TEST_DECLARE   (tcp_ref2)
TEST_DECLARE   (tcp_ref2b)
TEST_DECLARE   (tcp_ref3)
TEST_DECLARE   (tcp_ref4)
TEST_DECLARE   (udp_ref)
TEST_DECLARE   (udp_ref2)
TEST_DECLARE   (udp_ref3)
TEST_DECLARE   (pipe_ref)
TEST_DECLARE   (pipe_ref2)
TEST_DECLARE   (pipe_ref3)
TEST_DECLARE   (pipe_ref4)
TEST_DECLARE   (process_ref)
TEST_DECLARE   (has_ref)
TEST_DECLARE   (active)
TEST_DECLARE   (embed)
TEST_DECLARE   (async)
TEST_DECLARE   (async_null_cb)
TEST_DECLARE   (get_currentexe)
TEST_DECLARE   (process_title)
TEST_DECLARE   (cwd_and_chdir)
TEST_DECLARE   (get_memory)
TEST_DECLARE   (hrtime)
TEST_DECLARE   (getaddrinfo_fail)
TEST_DECLARE   (getaddrinfo_basic)
TEST_DECLARE   (getaddrinfo_concurrent)
TEST_DECLARE   (getsockname_tcp)
TEST_DECLARE   (getsockname_udp)
TEST_DECLARE   (fail_always)
TEST_DECLARE   (pass_always)
TEST_DECLARE   (spawn_fails)
TEST_DECLARE   (spawn_exit_code)
TEST_DECLARE   (spawn_stdout)
TEST_DECLARE   (spawn_stdin)
TEST_DECLARE   (spawn_stdio_greater_than_3)
TEST_DECLARE   (spawn_ignored_stdio)
TEST_DECLARE   (spawn_and_kill)
TEST_DECLARE   (spawn_detached)
TEST_DECLARE   (spawn_and_kill_with_std)
TEST_DECLARE   (spawn_and_ping)
TEST_DECLARE   (spawn_preserve_env)
TEST_DECLARE   (spawn_setuid_fails)
TEST_DECLARE   (spawn_setgid_fails)
TEST_DECLARE   (spawn_stdout_to_file)
TEST_DECLARE   (spawn_stdout_and_stderr_to_file)
TEST_DECLARE   (spawn_auto_unref)
TEST_DECLARE   (fs_poll)
TEST_DECLARE   (kill)
TEST_DECLARE   (fs_file_noent)
TEST_DECLARE   (fs_file_nametoolong)
TEST_DECLARE   (fs_file_loop)
TEST_DECLARE   (fs_file_async)
TEST_DECLARE   (fs_file_sync)
TEST_DECLARE   (fs_async_dir)
TEST_DECLARE   (fs_async_sendfile)
TEST_DECLARE   (fs_fstat)
TEST_DECLARE   (fs_chmod)
TEST_DECLARE   (fs_chown)
TEST_DECLARE   (fs_link)
TEST_DECLARE   (fs_readlink)
TEST_DECLARE   (fs_symlink)
TEST_DECLARE   (fs_symlink_dir)
TEST_DECLARE   (fs_utime)
TEST_DECLARE   (fs_futime)
TEST_DECLARE   (fs_file_open_append)
TEST_DECLARE   (fs_stat_missing_path)
TEST_DECLARE   (fs_read_file_eof)
TEST_DECLARE   (fs_event_watch_dir)
TEST_DECLARE   (fs_event_watch_file)
TEST_DECLARE   (fs_event_watch_file_twice)
TEST_DECLARE   (fs_event_watch_file_current_dir)
TEST_DECLARE   (fs_event_no_callback_after_close)
TEST_DECLARE   (fs_event_no_callback_on_close)
TEST_DECLARE   (fs_event_immediate_close)
TEST_DECLARE   (fs_event_close_with_pending_event)
TEST_DECLARE   (fs_event_close_in_callback)
TEST_DECLARE   (fs_event_start_and_close)
TEST_DECLARE   (fs_event_error_reporting)
TEST_DECLARE   (fs_readdir_empty_dir)
TEST_DECLARE   (fs_readdir_file)
TEST_DECLARE   (fs_open_dir)
TEST_DECLARE   (fs_rename_to_existing_file)
TEST_DECLARE   (threadpool_queue_work_simple)
TEST_DECLARE   (threadpool_queue_work_einval)
TEST_DECLARE   (threadpool_multiple_event_loops)
TEST_DECLARE   (threadpool_cancel_getaddrinfo)
TEST_DECLARE   (threadpool_cancel_work)
TEST_DECLARE   (threadpool_cancel_fs)
TEST_DECLARE   (threadpool_cancel_single)
TEST_DECLARE   (thread_local_storage)
TEST_DECLARE   (thread_mutex)
TEST_DECLARE   (thread_rwlock)
TEST_DECLARE   (thread_create)
TEST_DECLARE   (dlerror)
TEST_DECLARE   (poll_duplex)
TEST_DECLARE   (poll_unidirectional)
TEST_DECLARE   (poll_close)
TEST_DECLARE   (ip4_addr)
TEST_DECLARE   (ip6_addr_link_local)
#ifdef _WIN32
TEST_DECLARE   (spawn_detect_pipe_name_collisions_on_windows)
TEST_DECLARE   (argument_escaping)
TEST_DECLARE   (environment_creation)
TEST_DECLARE   (listen_with_simultaneous_accepts)
TEST_DECLARE   (listen_no_simultaneous_accepts)
TEST_DECLARE   (fs_stat_root)
#else
TEST_DECLARE   (emfile)
TEST_DECLARE   (close_fd)
TEST_DECLARE   (spawn_fs_open)
TEST_DECLARE   (spawn_setuid_setgid)
TEST_DECLARE   (we_get_signal)
TEST_DECLARE   (we_get_signals)
TEST_DECLARE   (signal_multiple_loops)
TEST_DECLARE   (closed_fd_events)
#endif
#ifdef __APPLE__
TEST_DECLARE   (osx_select)
#endif
HELPER_DECLARE (tcp4_echo_server)
HELPER_DECLARE (tcp6_echo_server)
HELPER_DECLARE (udp4_echo_server)
HELPER_DECLARE (pipe_echo_server)


TASK_LIST_START
  TEST_ENTRY_CUSTOM (platform_output, 0, 1, 5000)

#if 0
  TEST_ENTRY  (callback_order)
#endif
  TEST_ENTRY  (close_order)
  TEST_ENTRY  (run_once)
  TEST_ENTRY  (run_nowait)
  TEST_ENTRY  (loop_alive)
  TEST_ENTRY  (loop_stop)
  TEST_ENTRY  (loop_update_time)
  TEST_ENTRY  (barrier_1)
  TEST_ENTRY  (barrier_2)
  TEST_ENTRY  (barrier_3)
  TEST_ENTRY  (condvar_1)
  TEST_ENTRY  (condvar_2)
  TEST_ENTRY  (condvar_3)
  TEST_ENTRY  (condvar_4)
  TEST_ENTRY  (condvar_5)
  TEST_ENTRY  (semaphore_1)
  TEST_ENTRY  (semaphore_2)
  TEST_ENTRY  (semaphore_3)

  TEST_ENTRY  (pipe_connect_bad_name)
  TEST_ENTRY  (pipe_connect_to_file)

  TEST_ENTRY  (pipe_server_close)
  TEST_ENTRY  (tty)
  TEST_ENTRY  (stdio_over_pipes)
  TEST_ENTRY  (ipc_listen_before_write)
  TEST_ENTRY  (ipc_listen_after_write)
#ifndef _WIN32
  TEST_ENTRY  (ipc_send_recv_pipe)
#endif
  TEST_ENTRY  (ipc_send_recv_tcp)
  TEST_ENTRY  (ipc_tcp_connection)

  TEST_ENTRY  (tcp_ping_pong)
  TEST_HELPER (tcp_ping_pong, tcp4_echo_server)

  TEST_ENTRY  (tcp_ping_pong_v6)
  TEST_HELPER (tcp_ping_pong_v6, tcp6_echo_server)

  TEST_ENTRY  (pipe_ping_pong)
  TEST_HELPER (pipe_ping_pong, pipe_echo_server)

  TEST_ENTRY  (delayed_accept)
  TEST_ENTRY  (multiple_listen)

  TEST_ENTRY  (tcp_writealot)
  TEST_HELPER (tcp_writealot, tcp4_echo_server)

  TEST_ENTRY  (tcp_try_write)

  TEST_ENTRY  (tcp_open)
  TEST_HELPER (tcp_open, tcp4_echo_server)

  TEST_ENTRY  (tcp_shutdown_after_write)
  TEST_HELPER (tcp_shutdown_after_write, tcp4_echo_server)

  TEST_ENTRY  (tcp_connect_error_after_write)
  TEST_ENTRY  (tcp_bind_error_addrinuse)
  TEST_ENTRY  (tcp_bind_error_addrnotavail_1)
  TEST_ENTRY  (tcp_bind_error_addrnotavail_2)
  TEST_ENTRY  (tcp_bind_error_fault)
  TEST_ENTRY  (tcp_bind_error_inval)
  TEST_ENTRY  (tcp_bind_localhost_ok)
  TEST_ENTRY  (tcp_listen_without_bind)
  TEST_ENTRY  (tcp_connect_error_fault)
  TEST_ENTRY  (tcp_connect_timeout)
  TEST_ENTRY  (tcp_close_while_connecting)
  TEST_ENTRY  (tcp_close)
  TEST_ENTRY  (tcp_close_accept)
  TEST_ENTRY  (tcp_flags)
  TEST_ENTRY  (tcp_write_to_half_open_connection)
  TEST_ENTRY  (tcp_unexpected_read)

  TEST_ENTRY  (tcp_read_stop)
  TEST_HELPER (tcp_read_stop, tcp4_echo_server)

  TEST_ENTRY  (tcp_bind6_error_addrinuse)
  TEST_ENTRY  (tcp_bind6_error_addrnotavail)
  TEST_ENTRY  (tcp_bind6_error_fault)
  TEST_ENTRY  (tcp_bind6_error_inval)
  TEST_ENTRY  (tcp_bind6_localhost_ok)

  TEST_ENTRY  (udp_send_and_recv)
  TEST_ENTRY  (udp_dgram_too_big)
  TEST_ENTRY  (udp_dual_stack)
  TEST_ENTRY  (udp_ipv6_only)
  TEST_ENTRY  (udp_options)
  TEST_ENTRY  (udp_multicast_join)
  TEST_ENTRY  (udp_multicast_ttl)

  TEST_ENTRY  (udp_open)
  TEST_HELPER (udp_open, udp4_echo_server)

  TEST_ENTRY  (pipe_bind_error_addrinuse)
  TEST_ENTRY  (pipe_bind_error_addrnotavail)
  TEST_ENTRY  (pipe_bind_error_inval)
  TEST_ENTRY  (pipe_listen_without_bind)

  TEST_ENTRY  (connection_fail)
  TEST_ENTRY  (connection_fail_doesnt_auto_close)

  TEST_ENTRY  (shutdown_close_tcp)
  TEST_HELPER (shutdown_close_tcp, tcp4_echo_server)
  TEST_ENTRY  (shutdown_close_pipe)
  TEST_HELPER (shutdown_close_pipe, pipe_echo_server)

  TEST_ENTRY  (shutdown_eof)
  TEST_HELPER (shutdown_eof, tcp4_echo_server)

  TEST_ENTRY  (shutdown_twice)
  TEST_HELPER (shutdown_twice, tcp4_echo_server)

  TEST_ENTRY  (callback_stack)
  TEST_HELPER (callback_stack, tcp4_echo_server)

  TEST_ENTRY  (error_message)

  TEST_ENTRY  (timer)
  TEST_ENTRY  (timer_init)
  TEST_ENTRY  (timer_again)
  TEST_ENTRY  (timer_start_twice)
  TEST_ENTRY  (timer_order)
  TEST_ENTRY  (timer_huge_timeout)
  TEST_ENTRY  (timer_huge_repeat)
  TEST_ENTRY  (timer_run_once)
  TEST_ENTRY  (timer_from_check)

  TEST_ENTRY  (idle_starvation)

  TEST_ENTRY  (ref)
  TEST_ENTRY  (idle_ref)
  TEST_ENTRY  (fs_poll_ref)
  TEST_ENTRY  (async_ref)
  TEST_ENTRY  (prepare_ref)
  TEST_ENTRY  (check_ref)
  TEST_ENTRY  (unref_in_prepare_cb)
  TEST_ENTRY  (timer_ref)
  TEST_ENTRY  (timer_ref2)
  TEST_ENTRY  (fs_event_ref)
  TEST_ENTRY  (tcp_ref)
  TEST_ENTRY  (tcp_ref2)
  TEST_ENTRY  (tcp_ref2b)
  TEST_ENTRY  (tcp_ref3)
  TEST_HELPER (tcp_ref3, tcp4_echo_server)
  TEST_ENTRY  (tcp_ref4)
  TEST_HELPER (tcp_ref4, tcp4_echo_server)
  TEST_ENTRY  (udp_ref)
  TEST_ENTRY  (udp_ref2)
  TEST_ENTRY  (udp_ref3)
  TEST_HELPER (udp_ref3, udp4_echo_server)
  TEST_ENTRY  (pipe_ref)
  TEST_ENTRY  (pipe_ref2)
  TEST_ENTRY  (pipe_ref3)
  TEST_HELPER (pipe_ref3, pipe_echo_server)
  TEST_ENTRY  (pipe_ref4)
  TEST_HELPER (pipe_ref4, pipe_echo_server)
  TEST_ENTRY  (process_ref)
  TEST_ENTRY  (has_ref)

  TEST_ENTRY  (loop_handles)
  TEST_ENTRY  (walk_handles)

  TEST_ENTRY  (watcher_cross_stop)

  TEST_ENTRY  (active)

  TEST_ENTRY  (embed)

  TEST_ENTRY  (async)
  TEST_ENTRY  (async_null_cb)

  TEST_ENTRY  (get_currentexe)

  TEST_ENTRY  (process_title)

  TEST_ENTRY  (cwd_and_chdir)

  TEST_ENTRY  (get_memory)

  TEST_ENTRY  (get_loadavg)

  TEST_ENTRY  (hrtime)

  TEST_ENTRY_CUSTOM (getaddrinfo_fail, 0, 0, 10000)

  TEST_ENTRY  (getaddrinfo_basic)
  TEST_ENTRY  (getaddrinfo_concurrent)

  TEST_ENTRY  (getsockname_tcp)
  TEST_ENTRY  (getsockname_udp)

  TEST_ENTRY  (poll_duplex)
  TEST_ENTRY  (poll_unidirectional)
  TEST_ENTRY  (poll_close)

  TEST_ENTRY  (spawn_fails)
  TEST_ENTRY  (spawn_exit_code)
  TEST_ENTRY  (spawn_stdout)
  TEST_ENTRY  (spawn_stdin)
  TEST_ENTRY  (spawn_stdio_greater_than_3)
  TEST_ENTRY  (spawn_ignored_stdio)
  TEST_ENTRY  (spawn_and_kill)
  TEST_ENTRY  (spawn_detached)
  TEST_ENTRY  (spawn_and_kill_with_std)
  TEST_ENTRY  (spawn_and_ping)
  TEST_ENTRY  (spawn_preserve_env)
  TEST_ENTRY  (spawn_setuid_fails)
  TEST_ENTRY  (spawn_setgid_fails)
  TEST_ENTRY  (spawn_stdout_to_file)
  TEST_ENTRY  (spawn_stdout_and_stderr_to_file)
  TEST_ENTRY  (spawn_auto_unref)
  TEST_ENTRY  (fs_poll)
  TEST_ENTRY  (kill)

#ifdef _WIN32
  TEST_ENTRY  (spawn_detect_pipe_name_collisions_on_windows)
  TEST_ENTRY  (argument_escaping)
  TEST_ENTRY  (environment_creation)
  TEST_ENTRY  (listen_with_simultaneous_accepts)
  TEST_ENTRY  (listen_no_simultaneous_accepts)
  TEST_ENTRY  (fs_stat_root)
#else
  TEST_ENTRY  (emfile)
  TEST_ENTRY  (close_fd)
  TEST_ENTRY  (spawn_fs_open)
  TEST_ENTRY  (spawn_setuid_setgid)
  TEST_ENTRY  (we_get_signal)
  TEST_ENTRY  (we_get_signals)
  TEST_ENTRY  (signal_multiple_loops)
  TEST_ENTRY  (closed_fd_events)
#endif

#ifdef __APPLE__
  TEST_ENTRY (osx_select)
#endif

  TEST_ENTRY  (fs_file_noent)
  TEST_ENTRY  (fs_file_nametoolong)
  TEST_ENTRY  (fs_file_loop)
  TEST_ENTRY  (fs_file_async)
  TEST_ENTRY  (fs_file_sync)
  TEST_ENTRY  (fs_async_dir)
  TEST_ENTRY  (fs_async_sendfile)
  TEST_ENTRY  (fs_fstat)
  TEST_ENTRY  (fs_chmod)
  TEST_ENTRY  (fs_chown)
  TEST_ENTRY  (fs_utime)
  TEST_ENTRY  (fs_futime)
  TEST_ENTRY  (fs_readlink)
  TEST_ENTRY  (fs_symlink)
  TEST_ENTRY  (fs_symlink_dir)
  TEST_ENTRY  (fs_stat_missing_path)
  TEST_ENTRY  (fs_read_file_eof)
  TEST_ENTRY  (fs_file_open_append)
  TEST_ENTRY  (fs_event_watch_dir)
  TEST_ENTRY  (fs_event_watch_file)
  TEST_ENTRY  (fs_event_watch_file_twice)
  TEST_ENTRY  (fs_event_watch_file_current_dir)
  TEST_ENTRY  (fs_event_no_callback_after_close)
  TEST_ENTRY  (fs_event_no_callback_on_close)
  TEST_ENTRY  (fs_event_immediate_close)
  TEST_ENTRY  (fs_event_close_with_pending_event)
  TEST_ENTRY  (fs_event_close_in_callback)
  TEST_ENTRY  (fs_event_start_and_close)
  TEST_ENTRY  (fs_event_error_reporting)
  TEST_ENTRY  (fs_readdir_empty_dir)
  TEST_ENTRY  (fs_readdir_file)
  TEST_ENTRY  (fs_open_dir)
  TEST_ENTRY  (fs_rename_to_existing_file)
  TEST_ENTRY  (threadpool_queue_work_simple)
  TEST_ENTRY  (threadpool_queue_work_einval)
  TEST_ENTRY  (threadpool_multiple_event_loops)
  TEST_ENTRY  (threadpool_cancel_getaddrinfo)
  TEST_ENTRY  (threadpool_cancel_work)
  TEST_ENTRY  (threadpool_cancel_fs)
  TEST_ENTRY  (threadpool_cancel_single)
  TEST_ENTRY  (thread_local_storage)
  TEST_ENTRY  (thread_mutex)
  TEST_ENTRY  (thread_rwlock)
  TEST_ENTRY  (thread_create)
  TEST_ENTRY  (dlerror)
  TEST_ENTRY  (ip4_addr)
  TEST_ENTRY  (ip6_addr_link_local)
#if 0
  /* These are for testing the test runner. */
  TEST_ENTRY  (fail_always)
  TEST_ENTRY  (pass_always)
#endif
TASK_LIST_END