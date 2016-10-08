#!/bin/bash

DIR=`dirname $0`
echo $DIR
DIR=`readlink -f $DIR`
echo $DIR
BASE_DIR="$DIR/../"

source $BASE_DIR/BBB/catkin_ws/devel/setup.sh

#Get custom packages (this script will launch with 'sudo', so it'll be the root user
export ROS_PACKAGE_PATH=$ROS_PACKAGE_PATH:$BASE_DIR/BBB/ros_ws/
#Home directory for your user for logging
export ROS_HOME="$HOME"

#  export ROS_IP="192.168.1.10"

roslaunch hexapod_description gait_kinematics_imu.launch
