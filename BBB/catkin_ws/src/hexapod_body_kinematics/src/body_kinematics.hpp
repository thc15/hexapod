
#ifndef BODY_KINEMATICS_HPP_
#define BODY_KINEMATICS_HPP_

#include <ros/ros.h>
#include <kdl_parser/kdl_parser.hpp>
#include <hexapod_msgs/GetLegIKSolver.h>
#include <hexapod_msgs/LegsJointsState.h>
#include <hexapod_msgs/BodyState.h>
#include <hexapod_msgs/BodyCommand.h>

#define NUM_LEGS 6
#define NUM_JOINTS 3

class BodyKinematics {
	public:
		BodyKinematics();
		bool init();

	private:
		ros::NodeHandle node;
		std::string root_name, tip_name;
		std::vector<KDL::Frame> frames;
		hexapod_msgs::BodyState bs;
		hexapod_msgs::LegsJointsState legs;
		hexapod_msgs::GetLegIKSolver srv;
		const static unsigned int num_joints = NUM_JOINTS;
		const static unsigned int num_legs = NUM_LEGS;
		double z;

		KDL::Rotation rotation;
		KDL::Frame tibia_foot_frame, femur_frame;
		KDL::Vector offset_vector, rotate_correction, final_vector [num_legs];

		ros::ServiceClient client;
		ros::Publisher joints_pub;
		ros::Subscriber body_move_sub;
		ros::Subscriber body_cmd_sub;

		bool loadModel(const std::string xml);
		bool calculateKinematics (hexapod_msgs::BodyState* body_ptr);
		bool callService (KDL::Vector* vector);
		void teleopBodyMove (const hexapod_msgs::BodyStateConstPtr &body_state);
		void teleopBodyCmd (const hexapod_msgs::BodyCommandConstPtr &body_cmd);
};



#endif /* BODY_KINEMATICS_HPP_ */
