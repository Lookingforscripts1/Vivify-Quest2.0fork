// ohio sigma rizzler things

#include <iostream>
#include <stdexcept>
#include "SomeHeader.h"

void FindAssignedPrefab(void* prefab)
{
    try {
        auto assignedPrefab = try_cast<PrefabType>(prefab);
        // things
    } catch (const std::exception& e) {
        std::cerr << "Error casting prefab: " << e.what() << std::endl;
    }
}

void ReplaceNoteVisuals(NoteTransform* noteTransform)
{
    if (noteTransform == nullptr) {
        std::cerr << "Error: noteTransform is null." << std::endl;
        return;
    }
    
    for (auto& renderer : noteTransform->renderers) {
        if (renderer == nullptr) {
            std::cerr << "Warning: renderer is null, skipping..." << std::endl;
            continue;
        }
        // i hate crashes
    }
}

void ReplaceSaberVisuals(SaberType* saber)
{
    if (saber == nullptr) {
        std::cerr << "Error: saber is null." << std::endl;
        return;
    }
    
    for (auto& element : saber->elements) {
        if (element == nullptr) {
            std::cerr << "Warning: element is null, skipping..." << std::endl;
            continue;
        }
        // mango mango mango mustarrdd
    }
}


