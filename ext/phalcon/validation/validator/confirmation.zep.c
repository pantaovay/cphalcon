
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/object.h"


/**
 * Phalcon\Validation\Validator\Confirmation
 *
 * Checks that two values have the same value
 *
 * <code>
 * use Phalcon\Validation\Validator\Confirmation;
 *
 * $validator->add('password', new Confirmation([
 *     'message' => 'Password doesn\'t match confirmation',
 *     'with' => 'confirmPassword'
 * ]));
 *
 * $validator->add(['password', 'email'], new Confirmation([
 *     'message' => [
 *         'password' => 'Password doesn\'t match confirmation',
 *         'email' => 'Email  doesn\'t match confirmation'
 *     ],
 *     'with' => [
 *         'password => 'confirmPassword',
 *         'email' => 'confirmEmail'
 *     ]
 * ]));
 * </code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator_Confirmation) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Validation\\Validator, Confirmation, phalcon, validation_validator_confirmation, phalcon_validation_validator_ce, phalcon_validation_validator_confirmation_method_entry, 0);

	return SUCCESS;

}

/**
 * Executes the validation
 */
PHP_METHOD(Phalcon_Validation_Validator_Confirmation, validate) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval field;
	zval *validation, validation_sub, *field_param = NULL, fieldWith, value, valueWith, message, label, labelWith, replacePairs, code, _0, _2, _1$$3, _3$$4, _9$$4, _10$$4, _4$$5, _5$$7, _6$$9, _7$$10, _8$$11;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&validation_sub);
	ZVAL_UNDEF(&fieldWith);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&valueWith);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&label);
	ZVAL_UNDEF(&labelWith);
	ZVAL_UNDEF(&replacePairs);
	ZVAL_UNDEF(&code);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_6$$9);
	ZVAL_UNDEF(&_7$$10);
	ZVAL_UNDEF(&_8$$11);
	ZVAL_UNDEF(&field);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &validation, &field_param);

	if (unlikely(Z_TYPE_P(field_param) != IS_STRING && Z_TYPE_P(field_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'field' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(field_param) == IS_STRING)) {
		zephir_get_strval(&field, field_param);
	} else {
		ZEPHIR_INIT_VAR(&field);
		ZVAL_EMPTY_STRING(&field);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "with");
	ZEPHIR_CALL_METHOD(&fieldWith, this_ptr, "getoption", NULL, 0, &_0);
	zephir_check_call_status();
	if (Z_TYPE_P(&fieldWith) == IS_ARRAY) {
		zephir_array_fetch(&_1$$3, &fieldWith, &field, PH_NOISY | PH_READONLY, "phalcon/validation/validator/confirmation.zep", 65 TSRMLS_CC);
		ZEPHIR_CPY_WRT(&fieldWith, &_1$$3);
	}
	ZEPHIR_CALL_METHOD(&value, validation, "getvalue", NULL, 0, &field);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&valueWith, validation, "getvalue", NULL, 0, &fieldWith);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "compare", NULL, 452, &value, &valueWith);
	zephir_check_call_status();
	if (!(zephir_is_true(&_2))) {
		ZEPHIR_INIT_VAR(&_3$$4);
		ZVAL_STRING(&_3$$4, "label");
		ZEPHIR_CALL_METHOD(&label, this_ptr, "getoption", NULL, 0, &_3$$4);
		zephir_check_call_status();
		if (Z_TYPE_P(&label) == IS_ARRAY) {
			zephir_array_fetch(&_4$$5, &label, &field, PH_NOISY | PH_READONLY, "phalcon/validation/validator/confirmation.zep", 75 TSRMLS_CC);
			ZEPHIR_CPY_WRT(&label, &_4$$5);
		}
		if (ZEPHIR_IS_EMPTY(&label)) {
			ZEPHIR_CALL_METHOD(&label, validation, "getlabel", NULL, 0, &field);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(&_3$$4);
		ZVAL_STRING(&_3$$4, "labelWith");
		ZEPHIR_CALL_METHOD(&labelWith, this_ptr, "getoption", NULL, 0, &_3$$4);
		zephir_check_call_status();
		if (Z_TYPE_P(&labelWith) == IS_ARRAY) {
			zephir_array_fetch(&_5$$7, &labelWith, &field, PH_NOISY | PH_READONLY, "phalcon/validation/validator/confirmation.zep", 83 TSRMLS_CC);
			ZEPHIR_CPY_WRT(&labelWith, &_5$$7);
		}
		if (ZEPHIR_IS_EMPTY(&labelWith)) {
			ZEPHIR_CALL_METHOD(&labelWith, validation, "getlabel", NULL, 0, &fieldWith);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(&_3$$4);
		ZVAL_STRING(&_3$$4, "message");
		ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, 0, &_3$$4);
		zephir_check_call_status();
		if (Z_TYPE_P(&message) == IS_ARRAY) {
			zephir_array_fetch(&_6$$9, &message, &field, PH_NOISY | PH_READONLY, "phalcon/validation/validator/confirmation.zep", 91 TSRMLS_CC);
			ZEPHIR_CPY_WRT(&message, &_6$$9);
		}
		ZEPHIR_INIT_VAR(&replacePairs);
		zephir_create_array(&replacePairs, 2, 0 TSRMLS_CC);
		zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&replacePairs, SL(":with"), &labelWith, PH_COPY | PH_SEPARATE);
		if (ZEPHIR_IS_EMPTY(&message)) {
			ZEPHIR_INIT_VAR(&_7$$10);
			ZVAL_STRING(&_7$$10, "Confirmation");
			ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, &_7$$10);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(&_3$$4);
		ZVAL_STRING(&_3$$4, "code");
		ZEPHIR_CALL_METHOD(&code, this_ptr, "getoption", NULL, 0, &_3$$4);
		zephir_check_call_status();
		if (Z_TYPE_P(&code) == IS_ARRAY) {
			zephir_array_fetch(&_8$$11, &code, &field, PH_NOISY | PH_READONLY, "phalcon/validation/validator/confirmation.zep", 101 TSRMLS_CC);
			ZEPHIR_CPY_WRT(&code, &_8$$11);
		}
		ZEPHIR_INIT_NVAR(&_3$$4);
		object_init_ex(&_3$$4, phalcon_validation_message_ce);
		ZEPHIR_CALL_FUNCTION(&_9$$4, "strtr", NULL, 26, &message, &replacePairs);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_10$$4);
		ZVAL_STRING(&_10$$4, "Confirmation");
		ZEPHIR_CALL_METHOD(NULL, &_3$$4, "__construct", NULL, 450, &_9$$4, &field, &_10$$4, &code);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, &_3$$4);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

/**
 * Compare strings
 */
PHP_METHOD(Phalcon_Validation_Validator_Confirmation, compare) {

	zephir_fcall_cache_entry *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *a_param = NULL, *b_param = NULL, _0, _1, _2, _3$$3, _4$$3, _6$$3;
	zval a, b;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&a);
	ZVAL_UNDEF(&b);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &a_param, &b_param);

	zephir_get_strval(&a, a_param);
	zephir_get_strval(&b, b_param);


	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "ignoreCase");
	ZVAL_BOOL(&_2, 0);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getoption", NULL, 0, &_1, &_2);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		if (!((zephir_function_exists_ex(SL("mb_strtolower") TSRMLS_CC) == SUCCESS))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "Extension 'mbstring' is required", "phalcon/validation/validator/confirmation.zep", 122);
			return;
		}
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "utf-8");
		ZEPHIR_CALL_FUNCTION(&_4$$3, "mb_strtolower", &_5, 200, &a, &_3$$3);
		zephir_check_call_status();
		zephir_get_strval(&a, &_4$$3);
		ZEPHIR_INIT_NVAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "utf-8");
		ZEPHIR_CALL_FUNCTION(&_6$$3, "mb_strtolower", &_5, 200, &b, &_3$$3);
		zephir_check_call_status();
		zephir_get_strval(&b, &_6$$3);
	}
	RETURN_MM_BOOL(ZEPHIR_IS_EQUAL(&a, &b));

}

