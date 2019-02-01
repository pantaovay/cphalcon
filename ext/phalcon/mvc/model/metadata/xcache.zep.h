
extern zend_class_entry *phalcon_mvc_model_metadata_xcache_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_MetaData_Xcache);

PHP_METHOD(Phalcon_Mvc_Model_MetaData_Xcache, __construct);
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Xcache, read);
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Xcache, write);
zend_object *zephir_init_properties_Phalcon_Mvc_Model_MetaData_Xcache(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_xcache___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_xcache_read, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_xcache_write, 0, 0, 2)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_metadata_xcache_method_entry) {
	PHP_ME(Phalcon_Mvc_Model_MetaData_Xcache, __construct, arginfo_phalcon_mvc_model_metadata_xcache___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_Model_MetaData_Xcache, read, arginfo_phalcon_mvc_model_metadata_xcache_read, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_MetaData_Xcache, write, arginfo_phalcon_mvc_model_metadata_xcache_write, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
