//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a RdGen v1.07.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------
#include "PlayState.Generated.h"

namespace JetBrains {
namespace EditorPlugin {
std::string to_string(const PlayState & value)
{
    switch(value) {
    case PlayState::Idle: return "Idle";
    case PlayState::Play: return "Play";
    case PlayState::Pause: return "Pause";
    default: return std::to_string(static_cast<int32_t>(value));
    }
}
}
}
