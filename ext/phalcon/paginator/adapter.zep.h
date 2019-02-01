
extern zend_class_entry *phalcon_paginator_adapter_ce;

ZEPHIR_INIT_CLASS(Phalcon_Paginator_Adapter);

PHP_METHOD(Phalcon_Paginator_Adapter, getLimit);
PHP_METHOD(Phalcon_Paginator_Adapter, setCurrentPage);
PHP_METHOD(Phalcon_Paginator_Adapter, setLimit);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_paginator_adapter_getlimit, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_paginator_adapter_getlimit, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_paginator_adapter_setcurrentpage, 0, 1, Phalcon\\Paginator\\Adapter, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_paginator_adapter_setcurrentpage, 0, 1, IS_OBJECT, "Phalcon\\Paginator\\Adapter", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, page, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, page)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_paginator_adapter_setlimit, 0, 1, Phalcon\\Paginator\\Adapter, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_paginator_adapter_setlimit, 0, 1, IS_OBJECT, "Phalcon\\Paginator\\Adapter", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, limitRows, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, limitRows)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_paginator_adapter_method_entry) {
	PHP_ME(Phalcon_Paginator_Adapter, getLimit, arginfo_phalcon_paginator_adapter_getlimit, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Paginator_Adapter, setCurrentPage, arginfo_phalcon_paginator_adapter_setcurrentpage, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Paginator_Adapter, setLimit, arginfo_phalcon_paginator_adapter_setlimit, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
