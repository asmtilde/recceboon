#ifndef math_hpp
#define math_hpp

#include <cmath>

namespace asmtilde::recceboon::core::math // @brief Core Math Utilities, Constants, and Types for RecceBoon
{
    using experience_points = double; // @brief Type alias for experience points
    using dimension2d = struct { int width; int height; };  // @brief 2D dimension struct
    using vector2d = struct { double x; double y; };  // @brief 2D vector struct

    constexpr experience_points base_level_up_exp = 80.0;   // @brief base experience points for level up
    constexpr double xp_exponent_multiplier = 1.3;  // @brief exponent multiplier for experience points calculation

    constexpr int maximum_entity_level = 144;   // @brief maximum level an entity can reach
    constexpr int maximum_skill_level = 100;    // @brief maximum level a skill can reach
    constexpr int maximum_equipped_abilities = 3;   // @brief maximum number of equipped abilities
    constexpr int maximum_equipped_moves = 8;  // @brief maximum number of equipped moves

    inline experience_points calculate_level_up_xp(int current_level)   // @brief Calculate the xp required to level up
    {
        if (current_level >= maximum_entity_level)
        {
            return std::numeric_limits<experience_points>::max();   // Return the maximum value if at max level
        }
        return std::round(base_level_up_exp * std::pow(static_cast<experience_points>(current_level), xp_exponent_multiplier));
    }
}

#endif
