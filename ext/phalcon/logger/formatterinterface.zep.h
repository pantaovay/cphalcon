
extern zend_class_entry *phalcon_logger_formatterinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Logger_FormatterInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_formatterinterface_format, 0, 0, 3)
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
	ZEND_ARG_TYPE_INFO(0, timestamp, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, timestamp)
#endif
	ZEND_ARG_INFO(0, context)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_logger_formatterinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Logger_FormatterInterface, format, arginfo_phalcon_logger_formatterinterface_format)
	PHP_FE_END
};
