#ifndef LEATHERMAN_MESH_RESOURCE_H
#define LEATHERMAN_MESH_RESOURCE_H

// standard includes
#include <string>
#include <vector>

// system includes
#include <Eigen/Dense>
#include <geometric_shapes/shapes.h>
#include <geometry_msgs/PoseStamped.h>

namespace leatherman {

shapes::Mesh* createMeshFromBinaryStl(const char *filename);

shapes::Mesh* createMeshFromBinaryStlData(const char *data, unsigned int size);

void getMeshComponents(
    shapes::Mesh* mesh,
    std::vector<int>& triangles,
    std::vector<Eigen::Vector3d>& vertices);

bool getMeshComponentsFromResource(
    const std::string& resource,
    const Eigen::Vector3d& scale,
    std::vector<int>& triangles,
    std::vector<Eigen::Vector3d>& vertices);

double getColladaFileScale(std::string resource);

bool getLinkMesh(
    std::string urdf,
    std::string name,
    bool collision,
    std::string& mesh_resource,
    geometry_msgs::PoseStamped& pose);

} // namespace leatherman

#endif