
extern zend_class_entry *phalcon_session_adapter_redis_ce;

ZEPHIR_INIT_CLASS(Phalcon_Session_Adapter_Redis);

PHP_METHOD(Phalcon_Session_Adapter_Redis, getRedis);
PHP_METHOD(Phalcon_Session_Adapter_Redis, getLifetime);
PHP_METHOD(Phalcon_Session_Adapter_Redis, __construct);
PHP_METHOD(Phalcon_Session_Adapter_Redis, open);
PHP_METHOD(Phalcon_Session_Adapter_Redis, close);
PHP_METHOD(Phalcon_Session_Adapter_Redis, read);
PHP_METHOD(Phalcon_Session_Adapter_Redis, write);
PHP_METHOD(Phalcon_Session_Adapter_Redis, destroy);
PHP_METHOD(Phalcon_Session_Adapter_Redis, gc);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapter_redis___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_adapter_redis_open, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_adapter_redis_open, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_adapter_redis_close, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_adapter_redis_close, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_adapter_redis_read, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_adapter_redis_read, 0, 1, IS_STRING, NULL, 0)
#endif
	ZEND_ARG_INFO(0, sessionId)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_adapter_redis_write, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_adapter_redis_write, 0, 2, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, sessionId, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, sessionId)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, data, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, data)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_adapter_redis_destroy, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_adapter_redis_destroy, 0, 0, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_INFO(0, sessionId)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_adapter_redis_gc, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_adapter_redis_gc, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_session_adapter_redis_method_entry) {
	PHP_ME(Phalcon_Session_Adapter_Redis, getRedis, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter_Redis, getLifetime, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter_Redis, __construct, arginfo_phalcon_session_adapter_redis___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Session_Adapter_Redis, open, arginfo_phalcon_session_adapter_redis_open, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter_Redis, close, arginfo_phalcon_session_adapter_redis_close, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter_Redis, read, arginfo_phalcon_session_adapter_redis_read, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter_Redis, write, arginfo_phalcon_session_adapter_redis_write, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter_Redis, destroy, arginfo_phalcon_session_adapter_redis_destroy, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter_Redis, gc, arginfo_phalcon_session_adapter_redis_gc, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
