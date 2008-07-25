include $(top_srcdir)/build-aux/init.mk
include $(top_srcdir)/build-aux/autotest.mk

# Add available warnings flags.
AM_CXXFLAGS += $(WARNING_CXXFLAGS)

# Package the following files.
EXTRA_DIST += package.m4.in

# Clean atconfig (do not distribute it).
CLEANFILES += atconfig

# Source which are shared by all tests.
COMMON_SOURCES = common.hh

# file-test
check_PROGRAMS = file-test
file_test_SOURCES = file-test.cc $(COMMON_SOURCES)
file_test_LDADD = $(top_builddir)/src/libirobot-create.la

##################
# COMMANDS TESTS #
##################
# simple-test
check_PROGRAMS += simple-test
simple_test_SOURCES = simple-test.cc $(COMMON_SOURCES)
simple_test_LDADD = $(top_builddir)/src/libirobot-create.la

# baud-command-test
check_PROGRAMS += baud-command-test
baud_command_test_SOURCES = baud-command-test.cc $(COMMON_SOURCES)
baud_command_test_LDADD = $(top_builddir)/src/libirobot-create.la

# safe-command-test
check_PROGRAMS += safe-command-test
safe_command_test_SOURCES = safe-command-test.cc $(COMMON_SOURCES)
safe_command_test_LDADD = $(top_builddir)/src/libirobot-create.la

# full-command-test
check_PROGRAMS += full-command-test
full_command_test_SOURCES = full-command-test.cc $(COMMON_SOURCES)
full_command_test_LDADD = $(top_builddir)/src/libirobot-create.la

# demo-command-test
check_PROGRAMS += demo-command-test
demo_command_test_SOURCES = demo-command-test.cc $(COMMON_SOURCES)
demo_command_test_LDADD = $(top_builddir)/src/libirobot-create.la

# drive-command-test
check_PROGRAMS += drive-command-test
drive_command_test_SOURCES = drive-command-test.cc $(COMMON_SOURCES)
drive_command_test_LDADD = $(top_builddir)/src/libirobot-create.la

# drive-direct-command-test
check_PROGRAMS += drive-direct-command-test
drive_direct_command_test_SOURCES = drive-direct-command-test.cc \
					$(COMMON_SOURCES)
drive_direct_command_test_LDADD = $(top_builddir)/src/libirobot-create.la

# led-command-test
check_PROGRAMS += led-command-test
led_command_test_SOURCES = led-command-test.cc $(COMMON_SOURCES)
led_command_test_LDADD = $(top_builddir)/src/libirobot-create.la

# show-script-test
check_PROGRAMS += show-script-test
show_script_test_SOURCES = show-script-test.cc $(COMMON_SOURCES)
show_script_test_LDADD = $(top_builddir)/src/libirobot-create.la

# digital-outputs-test
check_PROGRAMS += digital-outputs-test
digital_outputs_test_SOURCES = digital-outputs-test.cc $(COMMON_SOURCES)
digital_outputs_test_LDADD = $(top_builddir)/src/libirobot-create.la

# ir-test
check_PROGRAMS += ir-test
ir_test_SOURCES = ir-test.cc $(COMMON_SOURCES)
ir_test_LDADD = $(top_builddir)/src/libirobot-create.la

# low-side-drivers-test.cc
check_PROGRAMS += low-side-drivers-test
low_side_drivers_test_SOURCES = low-side-drivers-test.cc $(COMMON_SOURCES)
low_side_drivers_test_LDADD = $(top_builddir)/src/libirobot-create.la

# pause-stream-test
check_PROGRAMS += pause-stream-test
pause_stream_test_SOURCES = pause-stream-test.cc $(COMMON_SOURCES)
pause_stream_test_LDADD = $(top_builddir)/src/libirobot-create.la

# play-script-test
check_PROGRAMS += play-script-test
play_script_test_SOURCES = play-script-test.cc $(COMMON_SOURCES)
play_script_test_LDADD = $(top_builddir)/src/libirobot-create.la

# play-song-test
check_PROGRAMS += play-song-test
play_song_test_SOURCES = play-song-test.cc $(COMMON_SOURCES)
play_song_test_LDADD = $(top_builddir)/src/libirobot-create.la

# pwm-low-side-drivers-test
check_PROGRAMS += pwm-low-side-drivers-test
pwm_low_side_drivers_test_SOURCES = pwm-low-side-drivers-test.cc \
					$(COMMON_SOURCES)
pwm_low_side_drivers_test_LDADD = $(top_builddir)/src/libirobot-create.la

# query-list-test
check_PROGRAMS += query-list-test
query_list_test_SOURCES = query-list-test.cc $(COMMON_SOURCES)
query_list_test_LDADD = $(top_builddir)/src/libirobot-create.la

# script-test
check_PROGRAMS += script-test
script_test_SOURCES = script-test.cc $(COMMON_SOURCES)
script_test_LDADD = $(top_builddir)/src/libirobot-create.la

# sensors-test
check_PROGRAMS += sensors-test
sensors_test_SOURCES = sensors-test.cc $(COMMON_SOURCES)
sensors_test_LDADD = $(top_builddir)/src/libirobot-create.la

# song-test
check_PROGRAMS += song-test
song_test_SOURCES = song-test.cc $(COMMON_SOURCES)
song_test_LDADD = $(top_builddir)/src/libirobot-create.la

# stream-test
check_PROGRAMS += stream-test
stream_test_SOURCES = stream-test.cc $(COMMON_SOURCES)
stream_test_LDADD = $(top_builddir)/src/libirobot-create.la

# wait-angle-test
check_PROGRAMS += wait-angle-test
wait_angle_test_SOURCES = wait-angle-test.cc $(COMMON_SOURCES)
wait_angle_test_LDADD = $(top_builddir)/src/libirobot-create.la

# wait-distance-test
check_PROGRAMS += wait-distance-test
wait_distance_test_SOURCES = wait-distance-test.cc $(COMMON_SOURCES)
wait_distance_test_LDADD = $(top_builddir)/src/libirobot-create.la

# wait-event-test
check_PROGRAMS += wait-event-test
wait_event_test_SOURCES = wait-event-test.cc $(COMMON_SOURCES)
wait_event_test_LDADD = $(top_builddir)/src/libirobot-create.la

# wait-time-test
check_PROGRAMS += wait-time-test
wait_time_test_SOURCES = wait-time-test.cc $(COMMON_SOURCES)
wait_time_test_LDADD = $(top_builddir)/src/libirobot-create.la

################
# SENSOR TESTS #
################
# bump-wheel-sensor-test
check_PROGRAMS += bump-wheel-sensor-test
bump_wheel_sensor_test_SOURCES = bump-wheel-sensor-test.cc $(COMMON_SOURCES)
bump_wheel_sensor_test_LDADD = $(top_builddir)/src/libirobot-create.la

# cliff-sensor-test
check_PROGRAMS += cliff-sensor-test
cliff_sensor_test_SOURCES = cliff-sensor-test.cc $(COMMON_SOURCES)
cliff_sensor_test_LDADD = $(top_builddir)/src/libirobot-create.la

# wall-sensor-test
check_PROGRAMS += wall-sensor-test
wall_sensor_test_SOURCES = wall-sensor-test.cc $(COMMON_SOURCES)
wall_sensor_test_LDADD = $(top_builddir)/src/libirobot-create.la

# battery-temperature-sensor-test
check_PROGRAMS += battery-temperature-sensor-test
battery_temperature_sensor_test_SOURCES = battery-temperature-sensor-test.cc \
						$(COMMON_SOURCES)
battery_temperature_sensor_test_LDADD = $(top_builddir)/src/libirobot-create.la

# buttons-sensor-test
check_PROGRAMS += buttons-sensor-test
buttons_sensor_test_SOURCES = buttons-sensor-test.cc $(COMMON_SOURCES)
buttons_sensor_test_LDADD = $(top_builddir)/src/libirobot-create.la

# cargo-bay-digital-inputs-sensor-test
check_PROGRAMS += cargo-bay-digital-inputs-sensor-test
cargo_bay_digital_inputs_sensor_test_SOURCES = \
	cargo-bay-digital-inputs-sensor-test.cc $(COMMON_SOURCES)
cargo_bay_digital_inputs_sensor_test_LDADD = \
	$(top_builddir)/src/libirobot-create.la

# charging-sources-sensor-test
check_PROGRAMS += charging-sources-sensor-test
charging_sources_sensor_test_SOURCES = charging-sources-sensor-test.cc \
					$(COMMON_SOURCES)
charging_sources_sensor_test_LDADD = $(top_builddir)/src/libirobot-create.la

# charging-state-sensor-test
check_PROGRAMS += charging-state-sensor-test
charging_state_sensor_test_SOURCES = charging-state-sensor-test.cc \
					$(COMMON_SOURCES)
charging_state_sensor_test_LDADD = $(top_builddir)/src/libirobot-create.la

# ir-sensor-test
check_PROGRAMS += ir-sensor-test
ir_sensor_test_SOURCES = ir-sensor-test.cc $(COMMON_SOURCES)
ir_sensor_test_LDADD = $(top_builddir)/src/libirobot-create.la

# oi-mode-sensor-test
check_PROGRAMS += oi-mode-sensor-test
oi_mode_sensor_test_SOURCES = oi-mode-sensor-test.cc $(COMMON_SOURCES)
oi_mode_sensor_test_LDADD = $(top_builddir)/src/libirobot-create.la

# overcurrent-sensor-test
check_PROGRAMS += overcurrent-sensor-test
overcurrent_sensor_test_SOURCES = overcurrent-sensor-test.cc $(COMMON_SOURCES)
overcurrent_sensor_test_LDADD = $(top_builddir)/src/libirobot-create.la

# song-sensor-test
check_PROGRAMS += song-sensor-test
song_sensor_test_SOURCES = song-sensor-test.cc $(COMMON_SOURCES)
song_sensor_test_LDADD = $(top_builddir)/src/libirobot-create.la

# stream-sensor-test
check_PROGRAMS += stream-sensor-test
stream_sensor_test_SOURCES = stream-sensor-test.cc $(COMMON_SOURCES)
stream_sensor_test_LDADD = $(top_builddir)/src/libirobot-create.la


.PHONY: generate-reference

# Re-generate reference outputs.
generate-reference:
	@echo "Generating references...";	\
	for i in $(check_PROGRAMS); do		\
	 IN="$(srcdir)/$$i.stdin";		\
	 OUT="$(srcdir)/$$i.stdout";		\
	 if test -f "$$IN"; then 		\
	  "./$$i" < $$IN > $$OUT || true;	\
	 else					\
	  "./$$i" > $$OUT || true;		\
	 fi					\
	done


# ------------ #
# Test suite.  #
# ------------ #

TESTSUITE_AT =					\
		baud-command-test.at		\
		demo-command-test.at		\
		digital-outputs-test.at		\
		drive-command-test.at		\
		drive-direct-command-test.at	\
		full-command-test.at		\
		ir-test.at			\
		led-command-test.at		\
		low-side-drivers-test.at	\
		pause-stream-test.at		\
		play-script-test.at		\
		play-song-test.at		\
		pwm-low-side-drivers-test.at	\
		query-list-test.at		\
		safe-command-test.at		\
		script-test.at			\
		sensors-test.at			\
		show-script-test.at		\
		song-test.at			\
		simple-test.at			\
		stream-test.at			\
		wait-angle-test.at		\
		wait-distance-test.at		\
		wait-event-test.at		\
		wait-time-test.at		\
		bump-wheel-sensor-test.at	\
		cliff-sensor-test.at		\
		wall-sensor-test.at		\
		battery-temperature-sensor-test.at	\
		buttons-sensor-test.at		\
		cargo-bay-digital-inputs-sensor-test.at	\
		charging-sources-sensor-test.at	\
		charging-state-sensor-test.at	\
		ir-sensor-test.at		\
		oi-mode-sensor-test.at		\
		overcurrent-sensor-test.at	\
		song-sensor-test.at		\
		stream-sensor-test.at

# Distribute reference files.
EXTRA_DIST +=						\
		baud-command-test.stdout		\
		demo-command-test.stdout		\
		digital-outputs-test.stdout		\
		drive-command-test.stdout		\
		drive-direct-command-test.stdout	\
		full-command-test.stdout		\
		ir-test.stdout				\
		led-command-test.stdout			\
		low-side-drivers-test.stdout		\
		pause-stream-test.stdout		\
		play-script-test.stdout			\
		play-song-test.stdout			\
		pwm-low-side-drivers-test.stdout	\
		query-list-test.stdout			\
		safe-command-test.stdout		\
		script-test.stdout			\
		sensors-test.stdout			\
		show-script-test.stdout			\
		song-test.stdout			\
		simple-test.stdout			\
		stream-test.stdout			\
		wait-angle-test.stdout			\
		wait-distance-test.stdout		\
		wait-event-test.stdout			\
		wait-time-test.stdout			\
		bump-wheel-sensor-test.stdout		\
		cliff-sensor-test.stdout		\
		wall-sensor-test.stdout			\
		battery-temperature-sensor-test.stdout	\
		buttons-sensor-test.stdout		\
		cargo-bay-digital-inputs-sensor-test.stdout	\
		charging-sources-sensor-test.stdout	\
		charging-state-sensor-test.stdout	\
		ir-sensor-test.stdout			\
		oi-mode-sensor-test.stdout		\
		overcurrent-sensor-test			\
		song-sensor-test.stdout			\
		stream-sensor-test.stdout
