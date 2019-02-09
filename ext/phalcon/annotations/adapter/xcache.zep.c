
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"


/**
 * Phalcon\Annotations\Adapter\Xcache
 *
 * Stores the parsed annotations to XCache. This adapter is suitable for production
 *
 *<code>
 * $annotations = new \Phalcon\Annotations\Adapter\Xcache();
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Annotations_Adapter_Xcache) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Annotations\\Adapter, Xcache, phalcon, annotations_adapter_xcache, phalcon_annotations_adapter_ce, phalcon_annotations_adapter_xcache_method_entry, 0);

	return SUCCESS;

}

/**
 * Reads parsed annotations from XCache
 *
 * @param string key
 * @return \Phalcon\Annotations\Reflection
 */
PHP_METHOD(Phalcon_Annotations_Adapter_Xcache, read) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, serialized, data, _0;
	zval key, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&serialized);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	if (UNEXPECTED(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(&key, key_param);
	} else {
		ZEPHIR_INIT_VAR(&key);
		ZVAL_EMPTY_STRING(&key);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_SV(&_1, "_PHAN", &key);
	zephir_fast_strtolower(&_0, &_1);
	ZEPHIR_CALL_FUNCTION(&serialized, "xcache_get", NULL, 84, &_0);
	zephir_check_call_status();
	if (Z_TYPE_P(&serialized) == IS_STRING) {
		ZEPHIR_CALL_FUNCTION(&data, "unserialize", NULL, 63, &serialized);
		zephir_check_call_status();
		if (Z_TYPE_P(&data) == IS_OBJECT) {
			RETURN_CCTOR(&data);
		}
	}
	RETURN_MM_BOOL(0);

}

/**
 * Writes parsed annotations to XCache
 */
PHP_METHOD(Phalcon_Annotations_Adapter_Xcache, write) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *data, data_sub, _0, _2;
	zval key, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &data);

	if (UNEXPECTED(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(&key, key_param);
	} else {
		ZEPHIR_INIT_VAR(&key);
		ZVAL_EMPTY_STRING(&key);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_SV(&_1, "_PHAN", &key);
	zephir_fast_strtolower(&_0, &_1);
	ZEPHIR_CALL_FUNCTION(&_2, "serialize", NULL, 62, data);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "xcache_set", NULL, 85, &_0, &_2);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

