FROM ros:humble-ros-core-jammy as repo-deps
# This layer installs basic tools and the direct dependencies of terrain-navigation.

SHELL ["/bin/bash", "-c"]

WORKDIR /root/dev/symk

# COPY mav_planning_rviz/package.xml mav_planning_rviz/package.xml
# COPY planner_msgs/package.xml planner_msgs/package.xml
# COPY terrain_navigation/package.xml terrain_navigation/package.xml
# COPY terrain_navigation_ros/package.xml terrain_navigation_ros/package.xml
# COPY terrain_planner/package.xml terrain_planner/package.xml
# COPY terrain_planner_benchmark/package.xml terrain_planner_benchmark/package.xml


RUN apt-get update
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y --no-install-recommends \
        build-essential \
        autoconf \
     && rm -rf /var/lib/apt/lists/*


FROM repo-deps as all-deps
# This layer installs dependencies of the other source packages.

# COPY dependencies.rosinstall src/terrain-navigation/dependencies.rosinstall
# RUN wstool init src src/terrain-navigation/dependencies.rosinstall
# RUN wstool update -t src -j4

# RUN apt-get update \
#     && rosdep update \
#     && source /opt/ros/noetic/setup.bash \
#     && rosdep install --from-paths src --ignore-src -y \
#     && rm -rf /var/lib/apt/lists/*