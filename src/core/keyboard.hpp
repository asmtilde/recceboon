#ifndef keyboard_hpp
#define keyboard_hpp

#include <SDL2/SDL.h>

namespace asmtilde::recceboon::core::keyboard // @brief Namespace for keyboard handling
{
    inline bool key_states[SDL_NUM_SCANCODES] = { false };  // @brief Array to hold the state of each key
    
    inline void poll_keyboard_event(const SDL_KeyboardEvent& key_event) // @brief Update key states based on keyboard events
    {
        switch (key_event.type)
        {
            case SDL_KEYDOWN:
                key_states[key_event.keysym.scancode] = true;
                break;
            case SDL_KEYUP:
                key_states[key_event.keysym.scancode] = false;
                break;
        }
    }
}

#endif
