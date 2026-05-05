MOD_EXTERN_FUNC void late_load() noexcept {
  logger.info("Starting late_load...");
  il2cpp_functions::Init();
  custom_types::Register::AutoRegister();
  Vivify::LateLoad();
  logger.info("late_load completed");
}
