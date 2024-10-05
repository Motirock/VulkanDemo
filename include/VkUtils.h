#ifndef VK_UTILS
#define VK_UTILS

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/hash.hpp>

#include <cmath>
#include <functional>

namespace VkUtils {
    enum Orientation {POSITIVE_X, NEGATIVE_X, POSITIVE_Y, NEGATIVE_Y, POSITIVE_Z, NEGATIVE_Z, ORIENTATION_MAX_ENUM};

    struct BlockVertex {
        uint32_t ID;

        static VkVertexInputBindingDescription getBindingDescription() {
            VkVertexInputBindingDescription bindingDescription{};
            bindingDescription.binding = 0;
            bindingDescription.stride = sizeof(BlockVertex);
            bindingDescription.inputRate = VK_VERTEX_INPUT_RATE_VERTEX;

            return bindingDescription;
        }

        static std::array<VkVertexInputAttributeDescription, 1> getAttributeDescriptions() {
            std::array<VkVertexInputAttributeDescription, 1> attributeDescriptions{};

            attributeDescriptions[0].binding = 0;
            attributeDescriptions[0].location = 0;
            attributeDescriptions[0].format = VK_FORMAT_R32_UINT;
            attributeDescriptions[0].offset = offsetof(BlockVertex, ID);

            return attributeDescriptions;
        }

        bool operator==(const BlockVertex &other) const {
            return ID == other.ID;
        }
    };

    struct BlockFaceInstance {
        glm::vec3 pos;
        uint32_t orientation;
        uint32_t blockID;
        glm::vec2 widthHeight;

        static VkVertexInputBindingDescription getBindingDescription() {
            VkVertexInputBindingDescription bindingDescription{};
            bindingDescription.binding = 1;
            bindingDescription.stride = sizeof(BlockFaceInstance);
            bindingDescription.inputRate = VK_VERTEX_INPUT_RATE_INSTANCE;

            return bindingDescription;
        }

        static std::array<VkVertexInputAttributeDescription, 4> getAttributeDescriptions() {
            std::array<VkVertexInputAttributeDescription, 4> attributeDescriptions{};

            attributeDescriptions[0].binding = 1;
            attributeDescriptions[0].location = 1;
            attributeDescriptions[0].format = VK_FORMAT_R32G32B32_SFLOAT;
            attributeDescriptions[0].offset = offsetof(BlockFaceInstance, pos);

            attributeDescriptions[1].binding = 1;
            attributeDescriptions[1].location = 2;
            attributeDescriptions[1].format = VK_FORMAT_R32_UINT;
            attributeDescriptions[1].offset = offsetof(BlockFaceInstance, orientation);

            attributeDescriptions[2].binding = 1;
            attributeDescriptions[2].location = 3;
            attributeDescriptions[2].format = VK_FORMAT_R32_UINT;
            attributeDescriptions[2].offset = offsetof(BlockFaceInstance, blockID);

            attributeDescriptions[3].binding = 1;
            attributeDescriptions[3].location = 4;
            attributeDescriptions[3].format = VK_FORMAT_R32G32_SFLOAT;
            attributeDescriptions[3].offset = offsetof(BlockFaceInstance, widthHeight);

            return attributeDescriptions;
        }

        bool operator==(const BlockFaceInstance &other) const {
            return pos == other.pos && orientation == other.orientation && blockID == other.blockID && widthHeight == other.widthHeight;
        }
    };

    struct PositionVertex {
        glm::vec3 position;

        static VkVertexInputBindingDescription getBindingDescription() {
            VkVertexInputBindingDescription bindingDescription{};
            bindingDescription.binding = 0;
            bindingDescription.stride = sizeof(PositionVertex);
            bindingDescription.inputRate = VK_VERTEX_INPUT_RATE_VERTEX;

            return bindingDescription;
        }

        static std::array<VkVertexInputAttributeDescription, 1> getAttributeDescriptions() {
            std::array<VkVertexInputAttributeDescription, 1> attributeDescriptions{};

            attributeDescriptions[0].binding = 0;
            attributeDescriptions[0].location = 0;
            attributeDescriptions[0].format = VK_FORMAT_R32G32B32_SFLOAT;
            attributeDescriptions[0].offset = offsetof(PositionVertex, position);

            return attributeDescriptions;
        }

        bool operator==(const PositionVertex &other) const {
            return position == other.position;
        }
    };
}

#endif