
extern zend_class_entry *phalcon_logger_adapter_blackhole_ce;

ZEPHIR_INIT_CLASS(Phalcon_Logger_Adapter_Blackhole);

PHP_METHOD(Phalcon_Logger_Adapter_Blackhole, getFormatter);
PHP_METHOD(Phalcon_Logger_Adapter_Blackhole, logInternal);
PHP_METHOD(Phalcon_Logger_Adapter_Blackhole, close);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_logger_adapter_blackhole_getformatter, 0, 0, Phalcon\\Logger\\FormatterInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_adapter_blackhole_getformatter, 0, 0, IS_OBJECT, "Phalcon\\Logger\\FormatterInterface", 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapter_blackhole_loginternal, 0, 0, 4)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, message)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, type, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, type)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, time, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, time)
#endif
	ZEND_ARG_ARRAY_INFO(0, context, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_adapter_blackhole_close, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_adapter_blackhole_close, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_logger_adapter_blackhole_method_entry) {
	PHP_ME(Phalcon_Logger_Adapter_Blackhole, getFormatter, arginfo_phalcon_logger_adapter_blackhole_getformatter, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Adapter_Blackhole, logInternal, arginfo_phalcon_logger_adapter_blackhole_loginternal, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Adapter_Blackhole, close, arginfo_phalcon_logger_adapter_blackhole_close, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
