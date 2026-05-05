#include "main.hpp"
#include "VivifyRuntime.hpp"
#include "custom-types/shared/register.hpp"
#include "scotland2/shared/modloader.h"

static modloader::ModInfo modInfo{MOD_ID, VERSION, 0};

Configuration &getConfig() {
  static Configuration config(modInfo);
  return config;
}

MOD_EXTERN_FUNC void setup(CModInfo *info) noexcept {
  try {
    *info = modInfo.to_c();
    getConfig().Load();
    Paper::Logger::RegisterFileContextId(logger.tag);
    logger.info("Vivify setup completed successfully");
  } catch (const std::exception& e) {
    logger.error("Setup failed: {}", e.what());
  }
}

MOD_EXTERN_FUNC void late_load() noexcept {
  try {
    logger.info("Starting late_load...");
    
    
    if (!il2cpp_functions::Init()) {
      logger.error("Failed to initialize il2cpp_functions");
      return;
    }
    logger.info("IL2CPP initialized successfully");
    
    // ohio rixzler 
    try {
      custom_types::Register::AutoRegister();
      logger.info("Custom types registered successfully");
    } catch (const std::exception& ex) {
      logger.error("Failed to register custom types: {}", ex.what());
      return;
    }
    
    // try touching vivify 
    try {
      Vivify::LateLoad();
      logger.info("Vivify runtime loaded successfully");
    } catch (const std::exception& ex) {
      logger.error("Failed to load Vivify runtime: {}", ex.what());
      return;
    }
    
    logger.info("late_load completed successfully");
  } catch (const std::exception& e) {
    logger.error("Unexpected error in late_load: {}", e.what());
  } catch (...) {
    logger.error("Unknown exception in late_load");
  }
}
