
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/variables.h"
#include "kernel/hash.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/string.h"
#include "kernel/concat.h"


/**
 * Phalcon\Validation
 *
 * Allows to validate data using custom or built-in validators
 */
ZEPHIR_INIT_CLASS(Phalcon_Validation) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon, Validation, phalcon, validation, phalcon_di_injectable_ce, phalcon_validation_method_entry, 0);

	zend_declare_property_null(phalcon_validation_ce, SL("_data"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_validation_ce, SL("_entity"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_validation_ce, SL("_validators"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_validation_ce, SL("_combinedFieldsValidators"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_validation_ce, SL("_filters"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_validation_ce, SL("_messages"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_validation_ce, SL("_defaultMessages"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_validation_ce, SL("_labels"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_validation_ce, SL("_values"), ZEND_ACC_PROTECTED TSRMLS_CC);

	phalcon_validation_ce->create_object = zephir_init_properties_Phalcon_Validation;

	zend_class_implements(phalcon_validation_ce TSRMLS_CC, 1, phalcon_validationinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Phalcon_Validation, setValidators) {

	zval *validators, validators_sub;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&validators_sub);

	zephir_fetch_params(0, 1, 0, &validators);



	zephir_update_property_zval(this_ptr, SL("_validators"), validators);

}

/**
 * Phalcon\Validation constructor
 */
PHP_METHOD(Phalcon_Validation, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL;
	zval *validators_param = NULL, _0$$3, _1$$3, _3$$3, _4$$3;
	zval validators;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&validators);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &validators_param);

	if (!validators_param) {
		ZEPHIR_INIT_VAR(&validators);
		array_init(&validators);
	} else {
		zephir_get_arrval(&validators, validators_param);
	}


	if (zephir_fast_count_int(&validators TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZEPHIR_INIT_NVAR(&_0$$3);
		zephir_create_closure_ex(&_0$$3, NULL, phalcon_0__closure_ce, SL("__invoke"));
		ZEPHIR_CALL_FUNCTION(&_1$$3, "array_filter", &_2, 448, &validators, &_0$$3);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("_validators"), &_1$$3);
		ZEPHIR_INIT_VAR(&_3$$3);
		ZEPHIR_INIT_NVAR(&_3$$3);
		zephir_create_closure_ex(&_3$$3, NULL, phalcon_1__closure_ce, SL("__invoke"));
		ZEPHIR_CALL_FUNCTION(&_4$$3, "array_filter", &_2, 448, &validators, &_3$$3);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("_combinedFieldsValidators"), &_4$$3);
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdefaultmessages", NULL, 0);
	zephir_check_call_status();
	if ((zephir_method_exists_ex(this_ptr, SL("initialize") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "initialize", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Validate a set of data according to a set of rules
 *
 * @param array|object data
 * @param object entity
 * @return \Phalcon\Validation\Message\Group
 */
PHP_METHOD(Phalcon_Validation, validate) {

	zend_bool _0$$7;
	zephir_fcall_cache_entry *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *data = NULL, data_sub, *entity = NULL, entity_sub, __$null, validators, messages, scope, field, validator, status, combinedFieldsValidators, *_1, _2$$10, _4$$10, _5$$14, _6$$14, *_7$$16, _8$$17, _9$$17, _10$$21, _11$$21, _12$$23;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&entity_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&validators);
	ZVAL_UNDEF(&messages);
	ZVAL_UNDEF(&scope);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&validator);
	ZVAL_UNDEF(&status);
	ZVAL_UNDEF(&combinedFieldsValidators);
	ZVAL_UNDEF(&_2$$10);
	ZVAL_UNDEF(&_4$$10);
	ZVAL_UNDEF(&_5$$14);
	ZVAL_UNDEF(&_6$$14);
	ZVAL_UNDEF(&_8$$17);
	ZVAL_UNDEF(&_9$$17);
	ZVAL_UNDEF(&_10$$21);
	ZVAL_UNDEF(&_11$$21);
	ZVAL_UNDEF(&_12$$23);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &data, &entity);

	if (!data) {
		data = &data_sub;
		data = &__$null;
	}
	if (!entity) {
		entity = &entity_sub;
		entity = &__$null;
	}


	ZEPHIR_OBS_VAR(&validators);
	zephir_read_property(&validators, this_ptr, SL("_validators"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&combinedFieldsValidators);
	zephir_read_property(&combinedFieldsValidators, this_ptr, SL("_combinedFieldsValidators"), PH_NOISY_CC);
	if (Z_TYPE_P(&validators) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "There are no validators to validate", "phalcon/validation.zep", 94);
		return;
	}
	zephir_update_property_zval(this_ptr, SL("_values"), &__$null);
	ZEPHIR_INIT_VAR(&messages);
	object_init_ex(&messages, phalcon_validation_message_group_ce);
	ZEPHIR_CALL_METHOD(NULL, &messages, "__construct", NULL, 3);
	zephir_check_call_status();
	if (Z_TYPE_P(entity) != IS_NULL) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setentity", NULL, 0, entity);
		zephir_check_call_status();
	}
	if ((zephir_method_exists_ex(this_ptr, SL("beforevalidation") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_CALL_METHOD(&status, this_ptr, "beforevalidation", NULL, 0, data, entity, &messages);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&status)) {
			RETURN_CCTOR(status);
		}
	}
	zephir_update_property_zval(this_ptr, SL("_messages"), &messages);
	if (Z_TYPE_P(data) != IS_NULL) {
		_0$$7 = Z_TYPE_P(data) == IS_ARRAY;
		if (!(_0$$7)) {
			_0$$7 = Z_TYPE_P(data) == IS_OBJECT;
		}
		if (_0$$7) {
			zephir_update_property_zval(this_ptr, SL("_data"), data);
		} else {
			zephir_var_dump(data TSRMLS_CC);
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "Invalid data to validate", "phalcon/validation.zep", 128);
			return;
		}
	}
	zephir_is_iterable(&validators, 0, "phalcon/validation.zep", 162);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&validators), _1)
	{
		ZEPHIR_INIT_NVAR(&scope);
		ZVAL_COPY(&scope, _1);
		if (Z_TYPE_P(&scope) != IS_ARRAY) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "The validator scope is not valid", "phalcon/validation.zep", 135);
			return;
		}
		ZEPHIR_OBS_NVAR(&field);
		zephir_array_fetch_long(&field, &scope, 0, PH_NOISY, "phalcon/validation.zep", 138 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(&validator);
		zephir_array_fetch_long(&validator, &scope, 1, PH_NOISY, "phalcon/validation.zep", 139 TSRMLS_CC);
		if (Z_TYPE_P(&validator) != IS_OBJECT) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "One of the validators is not valid", "phalcon/validation.zep", 142);
			return;
		}
		ZEPHIR_CALL_METHOD(&_2$$10, this_ptr, "prechecking", &_3, 0, &field, &validator);
		zephir_check_call_status();
		if (zephir_is_true(&_2$$10)) {
			continue;
		}
		ZEPHIR_CALL_METHOD(&_4$$10, &validator, "validate", NULL, 0, this_ptr, &field);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_4$$10)) {
			ZEPHIR_INIT_NVAR(&_6$$14);
			ZVAL_STRING(&_6$$14, "cancelOnFail");
			ZEPHIR_CALL_METHOD(&_5$$14, &validator, "getoption", NULL, 0, &_6$$14);
			zephir_check_call_status();
			if (zephir_is_true(&_5$$14)) {
				break;
			}
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&scope);
	if (!(ZEPHIR_IS_EMPTY(&combinedFieldsValidators))) {
		zephir_is_iterable(&combinedFieldsValidators, 0, "phalcon/validation.zep", 191);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&combinedFieldsValidators), _7$$16)
		{
			ZEPHIR_INIT_NVAR(&scope);
			ZVAL_COPY(&scope, _7$$16);
			if (Z_TYPE_P(&scope) != IS_ARRAY) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "The validator scope is not valid", "phalcon/validation.zep", 165);
				return;
			}
			ZEPHIR_OBS_NVAR(&field);
			zephir_array_fetch_long(&field, &scope, 0, PH_NOISY, "phalcon/validation.zep", 168 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&validator);
			zephir_array_fetch_long(&validator, &scope, 1, PH_NOISY, "phalcon/validation.zep", 169 TSRMLS_CC);
			if (Z_TYPE_P(&validator) != IS_OBJECT) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "One of the validators is not valid", "phalcon/validation.zep", 172);
				return;
			}
			ZEPHIR_CALL_METHOD(&_8$$17, this_ptr, "prechecking", &_3, 0, &field, &validator);
			zephir_check_call_status();
			if (zephir_is_true(&_8$$17)) {
				continue;
			}
			ZEPHIR_CALL_METHOD(&_9$$17, &validator, "validate", NULL, 0, this_ptr, &field);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_9$$17)) {
				ZEPHIR_INIT_NVAR(&_11$$21);
				ZVAL_STRING(&_11$$21, "cancelOnFail");
				ZEPHIR_CALL_METHOD(&_10$$21, &validator, "getoption", NULL, 0, &_11$$21);
				zephir_check_call_status();
				if (zephir_is_true(&_10$$21)) {
					break;
				}
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&scope);
	}
	if ((zephir_method_exists_ex(this_ptr, SL("aftervalidation") TSRMLS_CC) == SUCCESS)) {
		zephir_read_property(&_12$$23, this_ptr, SL("_messages"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "aftervalidation", NULL, 0, data, entity, &_12$$23);
		zephir_check_call_status();
	}
	RETURN_MM_MEMBER(this_ptr, "_messages");

}

/**
 * Adds a validator to a field
 */
PHP_METHOD(Phalcon_Validation, add) {

	zval _0$$4, _2$$6, _3$$7;
	zval *field, field_sub, *validator, validator_sub, singleField, *_1$$5;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&validator_sub);
	ZVAL_UNDEF(&singleField);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_2$$6);
	ZVAL_UNDEF(&_3$$7);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &field, &validator);



	if (Z_TYPE_P(field) == IS_ARRAY) {
		if (zephir_instance_of_ev(validator, phalcon_validation_combinedfieldsvalidator_ce TSRMLS_CC)) {
			ZEPHIR_INIT_VAR(&_0$$4);
			zephir_create_array(&_0$$4, 2, 0 TSRMLS_CC);
			zephir_array_fast_append(&_0$$4, field);
			zephir_array_fast_append(&_0$$4, validator);
			zephir_update_property_array_append(this_ptr, SL("_combinedFieldsValidators"), &_0$$4 TSRMLS_CC);
		} else {
			zephir_is_iterable(field, 0, "phalcon/validation.zep", 218);
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(field), _1$$5)
			{
				ZEPHIR_INIT_NVAR(&singleField);
				ZVAL_COPY(&singleField, _1$$5);
				ZEPHIR_INIT_NVAR(&_2$$6);
				zephir_create_array(&_2$$6, 2, 0 TSRMLS_CC);
				zephir_array_fast_append(&_2$$6, &singleField);
				zephir_array_fast_append(&_2$$6, validator);
				zephir_update_property_array_append(this_ptr, SL("_validators"), &_2$$6 TSRMLS_CC);
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&singleField);
		}
	} else if (Z_TYPE_P(field) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_3$$7);
		zephir_create_array(&_3$$7, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(&_3$$7, field);
		zephir_array_fast_append(&_3$$7, validator);
		zephir_update_property_array_append(this_ptr, SL("_validators"), &_3$$7 TSRMLS_CC);
	} else {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "Field must be passed as array of fields or string", "phalcon/validation.zep", 224);
		return;
	}
	RETURN_THIS();

}

/**
 * Alias of `add` method
 */
PHP_METHOD(Phalcon_Validation, rule) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *field, field_sub, *validator, validator_sub;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&validator_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &field, &validator);



	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "add", NULL, 0, field, validator);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Adds the validators to a field
 */
PHP_METHOD(Phalcon_Validation, rules) {

	zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval validators;
	zval *field, field_sub, *validators_param = NULL, validator, *_0;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&validator);
	ZVAL_UNDEF(&validators);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &field, &validators_param);

	ZEPHIR_OBS_COPY_OR_DUP(&validators, validators_param);


	zephir_is_iterable(&validators, 0, "phalcon/validation.zep", 250);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&validators), _0)
	{
		ZEPHIR_INIT_NVAR(&validator);
		ZVAL_COPY(&validator, _0);
		if (zephir_instance_of_ev(&validator, phalcon_validation_validatorinterface_ce TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "add", &_1, 0, field, &validator);
			zephir_check_call_status();
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&validator);
	RETURN_THIS();

}

/**
 * Adds filters to the field
 *
 * @param string field
 * @param array|string filters
 * @return \Phalcon\Validation
 */
PHP_METHOD(Phalcon_Validation, setFilters) {

	zval *field, field_sub, *filters, filters_sub, singleField, *_0$$3;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&filters_sub);
	ZVAL_UNDEF(&singleField);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &field, &filters);



	if (Z_TYPE_P(field) == IS_ARRAY) {
		zephir_is_iterable(field, 0, "phalcon/validation.zep", 267);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(field), _0$$3)
		{
			ZEPHIR_INIT_NVAR(&singleField);
			ZVAL_COPY(&singleField, _0$$3);
			zephir_update_property_array(this_ptr, SL("_filters"), &singleField, filters TSRMLS_CC);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&singleField);
	} else if (Z_TYPE_P(field) == IS_STRING) {
		zephir_update_property_array(this_ptr, SL("_filters"), field, filters TSRMLS_CC);
	} else {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "Field must be passed as array of fields or string.", "phalcon/validation.zep", 272);
		return;
	}
	RETURN_THIS();

}

/**
 * Returns all the filters or a specific one
 *
 * @param string field
 * @return mixed
 */
PHP_METHOD(Phalcon_Validation, getFilters) {

	zend_bool _0;
	zval *field_param = NULL, filters, fieldFilters;
	zval field;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&filters);
	ZVAL_UNDEF(&fieldFilters);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &field_param);

	if (!field_param) {
		ZEPHIR_INIT_VAR(&field);
		ZVAL_STRING(&field, "");
	} else {
		zephir_get_strval(&field, field_param);
	}


	zephir_read_property(&filters, this_ptr, SL("_filters"), PH_NOISY_CC | PH_READONLY);
	_0 = ZEPHIR_IS_STRING_IDENTICAL(&field, "");
	if (!(_0)) {
		_0 = ZEPHIR_IS_STRING_IDENTICAL(&field, "");
	}
	if (_0) {
		RETURN_CTOR(filters);
	}
	if (!(zephir_array_isset_fetch(&fieldFilters, &filters, &field, 1 TSRMLS_CC))) {
		RETURN_MM_NULL();
	}
	RETURN_CTOR(fieldFilters);

}

/**
 * Returns the validators added to the validation
 */
PHP_METHOD(Phalcon_Validation, getValidators) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_validators");

}

/**
 * Sets the bound entity
 *
 * @param object entity
 */
PHP_METHOD(Phalcon_Validation, setEntity) {

	zval *entity, entity_sub;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&entity_sub);

	zephir_fetch_params(0, 1, 0, &entity);



	if (Z_TYPE_P(entity) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalcon_validation_exception_ce, "Entity must be an object", "phalcon/validation.zep", 315);
		return;
	}
	zephir_update_property_zval(this_ptr, SL("_entity"), entity);

}

/**
 * Returns the bound entity
 *
 * @return object
 */
PHP_METHOD(Phalcon_Validation, getEntity) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_entity");

}

/**
 * Adds default messages to validators
 */
PHP_METHOD(Phalcon_Validation, setDefaultMessages) {

	zval *messages_param = NULL, defaultMessages, _0$$3;
	zval messages;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&messages);
	ZVAL_UNDEF(&defaultMessages);
	ZVAL_UNDEF(&_0$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &messages_param);

	if (!messages_param) {
		ZEPHIR_INIT_VAR(&messages);
		array_init(&messages);
	} else {
		zephir_get_arrval(&messages, messages_param);
	}


	ZEPHIR_INIT_VAR(&defaultMessages);
	zephir_create_array(&defaultMessages, 25, 0 TSRMLS_CC);
	add_assoc_stringl_ex(&defaultMessages, SL("Alnum"), SL("Field :field must contain only letters and numbers"));
	add_assoc_stringl_ex(&defaultMessages, SL("Alpha"), SL("Field :field must contain only letters"));
	add_assoc_stringl_ex(&defaultMessages, SL("Between"), SL("Field :field must be within the range of :min to :max"));
	add_assoc_stringl_ex(&defaultMessages, SL("Confirmation"), SL("Field :field must be the same as :with"));
	add_assoc_stringl_ex(&defaultMessages, SL("Digit"), SL("Field :field must be numeric"));
	add_assoc_stringl_ex(&defaultMessages, SL("Email"), SL("Field :field must be an email address"));
	add_assoc_stringl_ex(&defaultMessages, SL("ExclusionIn"), SL("Field :field must not be a part of list: :domain"));
	add_assoc_stringl_ex(&defaultMessages, SL("FileEmpty"), SL("Field :field must not be empty"));
	add_assoc_stringl_ex(&defaultMessages, SL("FileIniSize"), SL("File :field exceeds the maximum file size"));
	add_assoc_stringl_ex(&defaultMessages, SL("FileMaxResolution"), SL("File :field must not exceed :max resolution"));
	add_assoc_stringl_ex(&defaultMessages, SL("FileMinResolution"), SL("File :field must be at least :min resolution"));
	add_assoc_stringl_ex(&defaultMessages, SL("FileSize"), SL("File :field exceeds the size of :max"));
	add_assoc_stringl_ex(&defaultMessages, SL("FileType"), SL("File :field must be of type: :types"));
	add_assoc_stringl_ex(&defaultMessages, SL("FileValid"), SL("Field :field is not valid"));
	add_assoc_stringl_ex(&defaultMessages, SL("Identical"), SL("Field :field does not have the expected value"));
	add_assoc_stringl_ex(&defaultMessages, SL("InclusionIn"), SL("Field :field must be a part of list: :domain"));
	add_assoc_stringl_ex(&defaultMessages, SL("Numericality"), SL("Field :field does not have a valid numeric format"));
	add_assoc_stringl_ex(&defaultMessages, SL("PresenceOf"), SL("Field :field is required"));
	add_assoc_stringl_ex(&defaultMessages, SL("Regex"), SL("Field :field does not match the required format"));
	add_assoc_stringl_ex(&defaultMessages, SL("TooLong"), SL("Field :field must not exceed :max characters long"));
	add_assoc_stringl_ex(&defaultMessages, SL("TooShort"), SL("Field :field must be at least :min characters long"));
	add_assoc_stringl_ex(&defaultMessages, SL("Uniqueness"), SL("Field :field must be unique"));
	add_assoc_stringl_ex(&defaultMessages, SL("Url"), SL("Field :field must be a url"));
	add_assoc_stringl_ex(&defaultMessages, SL("CreditCard"), SL("Field :field is not valid for a credit card number"));
	add_assoc_stringl_ex(&defaultMessages, SL("Date"), SL("Field :field is not a valid date"));
	if (zephir_fast_count_int(&messages TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_fast_array_merge(&_0$$3, &defaultMessages, &messages TSRMLS_CC);
		zephir_update_property_zval(this_ptr, SL("_defaultMessages"), &_0$$3);
		RETURN_MM_MEMBER(this_ptr, "_defaultMessages");
	}
	zephir_update_property_zval(this_ptr, SL("_defaultMessages"), &defaultMessages);
	RETURN_CCTOR(defaultMessages);

}

/**
 * Get default message for validator type
 */
PHP_METHOD(Phalcon_Validation, getDefaultMessage) {

	zval *type_param = NULL, defaultMessage, _0;
	zval type;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&defaultMessage);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &type_param);

	if (unlikely(Z_TYPE_P(type_param) != IS_STRING && Z_TYPE_P(type_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'type' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(type_param) == IS_STRING)) {
		zephir_get_strval(&type, type_param);
	} else {
		ZEPHIR_INIT_VAR(&type);
		ZVAL_EMPTY_STRING(&type);
	}


	zephir_read_property(&_0, this_ptr, SL("_defaultMessages"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&defaultMessage, &_0, &type, 1 TSRMLS_CC)) {
		RETURN_CTOR(defaultMessage);
	}
	RETURN_MM_STRING("");

}

/**
 * Returns the registered validators
 */
PHP_METHOD(Phalcon_Validation, getMessages) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_messages");

}

/**
 * Adds labels for fields
 */
PHP_METHOD(Phalcon_Validation, setLabels) {

	zval *labels_param = NULL;
	zval labels;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&labels);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &labels_param);

	ZEPHIR_OBS_COPY_OR_DUP(&labels, labels_param);


	zephir_update_property_zval(this_ptr, SL("_labels"), &labels);
	ZEPHIR_MM_RESTORE();

}

/**
 * Get label for field
 *
 * @param string field
 * @return string
 */
PHP_METHOD(Phalcon_Validation, getLabel) {

	zend_bool _0;
	zval *field, field_sub, labels, value;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&labels);
	ZVAL_UNDEF(&value);

	zephir_fetch_params(0, 1, 0, &field);



	zephir_read_property(&labels, this_ptr, SL("_labels"), PH_NOISY_CC | PH_READONLY);
	_0 = Z_TYPE_P(&labels) == IS_ARRAY;
	if (_0) {
		_0 = Z_TYPE_P(field) != IS_ARRAY;
	}
	if (_0) {
		if (zephir_array_isset_fetch(&value, &labels, field, 1 TSRMLS_CC)) {
			RETURN_CTORW(value);
		}
	} else if (Z_TYPE_P(field) == IS_ARRAY) {
		zephir_fast_join_str(return_value, SL(", "), field TSRMLS_CC);
		return;
	}
	RETVAL_ZVAL(field, 1, 0);
	return;

}

/**
 * Appends a message to the messages list
 */
PHP_METHOD(Phalcon_Validation, appendMessage) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *message, message_sub, messages;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&messages);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message);



	ZEPHIR_OBS_VAR(&messages);
	zephir_read_property(&messages, this_ptr, SL("_messages"), PH_NOISY_CC);
	if (Z_TYPE_P(&messages) != IS_OBJECT) {
		ZEPHIR_INIT_NVAR(&messages);
		object_init_ex(&messages, phalcon_validation_message_group_ce);
		ZEPHIR_CALL_METHOD(NULL, &messages, "__construct", NULL, 3);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, &messages, "appendmessage", NULL, 449, message);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("_messages"), &messages);
	RETURN_THIS();

}

/**
 * Assigns the data to an entity
 * The entity is used to obtain the validation values
 *
 * @param object entity
 * @param array|object data
 * @return \Phalcon\Validation
 */
PHP_METHOD(Phalcon_Validation, bind) {

	zend_bool _0;
	zval *entity, entity_sub, *data, data_sub;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&entity_sub);
	ZVAL_UNDEF(&data_sub);

	zephir_fetch_params(0, 2, 0, &entity, &data);



	if (Z_TYPE_P(entity) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalcon_validation_exception_ce, "Entity must be an object", "phalcon/validation.zep", 455);
		return;
	}
	_0 = Z_TYPE_P(data) != IS_ARRAY;
	if (_0) {
		_0 = Z_TYPE_P(data) != IS_OBJECT;
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalcon_validation_exception_ce, "Data to validate must be an array or object", "phalcon/validation.zep", 459);
		return;
	}
	zephir_update_property_zval(this_ptr, SL("_entity"), entity);
	zephir_update_property_zval(this_ptr, SL("_data"), data);
	RETURN_THISW();

}

/**
 * Gets the a value to validate in the array/object data source
 *
 * @param string field
 * @return mixed
 */
PHP_METHOD(Phalcon_Validation, getValue) {

	zend_bool _1;
	zephir_fcall_cache_entry *_2 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *field_param = NULL, entity, method, value, data, values, filters, fieldFilters, dependencyInjector, filterService, _0$$3, _3$$20;
	zval field;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&entity);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&filters);
	ZVAL_UNDEF(&fieldFilters);
	ZVAL_UNDEF(&dependencyInjector);
	ZVAL_UNDEF(&filterService);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_3$$20);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &field_param);

	zephir_get_strval(&field, field_param);


	ZEPHIR_OBS_VAR(&entity);
	zephir_read_property(&entity, this_ptr, SL("_entity"), PH_NOISY_CC);
	if (Z_TYPE_P(&entity) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_camelize(&_0$$3, &field, NULL  );
		ZEPHIR_INIT_VAR(&method);
		ZEPHIR_CONCAT_SV(&method, "get", &_0$$3);
		if ((zephir_method_exists(&entity, &method TSRMLS_CC)  == SUCCESS)) {
			ZEPHIR_CALL_METHOD_ZVAL(&value, &entity, &method, NULL, 0);
			zephir_check_call_status();
		} else {
			if ((zephir_method_exists_ex(&entity, SL("readattribute") TSRMLS_CC) == SUCCESS)) {
				ZEPHIR_CALL_METHOD(&value, &entity, "readattribute", NULL, 0, &field);
				zephir_check_call_status();
			} else {
				ZEPHIR_INIT_NVAR(&value);
				if (zephir_isset_property_zval(&entity, &field TSRMLS_CC)) {
					zephir_read_property_zval(&value, &entity, &field, PH_NOISY_CC);
				} else {
					ZVAL_NULL(&value);
				}
			}
		}
		RETURN_CCTOR(value);
	}
	ZEPHIR_OBS_VAR(&data);
	zephir_read_property(&data, this_ptr, SL("_data"), PH_NOISY_CC);
	_1 = Z_TYPE_P(&data) != IS_ARRAY;
	if (_1) {
		_1 = Z_TYPE_P(&data) != IS_OBJECT;
	}
	if (_1) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "There is no data to validate", "phalcon/validation.zep", 504);
		return;
	}
	ZEPHIR_OBS_VAR(&values);
	zephir_read_property(&values, this_ptr, SL("_values"), PH_NOISY_CC);
	ZEPHIR_OBS_NVAR(&value);
	if (zephir_array_isset_fetch(&value, &values, &field, 0 TSRMLS_CC)) {
		RETURN_CCTOR(value);
	}
	ZEPHIR_INIT_NVAR(&value);
	ZVAL_NULL(&value);
	if (Z_TYPE_P(&data) == IS_ARRAY) {
		if (zephir_array_isset(&data, &field)) {
			ZEPHIR_OBS_NVAR(&value);
			zephir_array_fetch(&value, &data, &field, PH_NOISY, "phalcon/validation.zep", 516 TSRMLS_CC);
		}
	} else {
		if (Z_TYPE_P(&data) == IS_OBJECT) {
			if (zephir_isset_property_zval(&data, &field TSRMLS_CC)) {
				ZEPHIR_OBS_NVAR(&value);
				zephir_read_property_zval(&value, &data, &field, PH_NOISY_CC);
			}
		}
	}
	if (Z_TYPE_P(&value) == IS_NULL) {
		RETURN_MM_NULL();
	}
	ZEPHIR_OBS_VAR(&filters);
	zephir_read_property(&filters, this_ptr, SL("_filters"), PH_NOISY_CC);
	if (Z_TYPE_P(&filters) == IS_ARRAY) {
		ZEPHIR_OBS_VAR(&fieldFilters);
		if (zephir_array_isset_fetch(&fieldFilters, &filters, &field, 0 TSRMLS_CC)) {
			if (zephir_is_true(&fieldFilters)) {
				ZEPHIR_CALL_METHOD(&dependencyInjector, this_ptr, "getdi", NULL, 0);
				zephir_check_call_status();
				if (Z_TYPE_P(&dependencyInjector) != IS_OBJECT) {
					ZEPHIR_CALL_CE_STATIC(&dependencyInjector, phalcon_di_ce, "getdefault", &_2, 1);
					zephir_check_call_status();
					if (Z_TYPE_P(&dependencyInjector) != IS_OBJECT) {
						ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "A dependency injector is required to obtain the 'filter' service", "phalcon/validation.zep", 541);
						return;
					}
				}
				ZEPHIR_INIT_VAR(&_3$$20);
				ZVAL_STRING(&_3$$20, "filter");
				ZEPHIR_CALL_METHOD(&filterService, &dependencyInjector, "getshared", NULL, 0, &_3$$20);
				zephir_check_call_status();
				if (Z_TYPE_P(&filterService) != IS_OBJECT) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "Returned 'filter' service is invalid", "phalcon/validation.zep", 547);
					return;
				}
				ZEPHIR_RETURN_CALL_METHOD(&filterService, "sanitize", NULL, 0, &value, &fieldFilters);
				zephir_check_call_status();
				RETURN_MM();
			}
		}
	}
	zephir_update_property_array(this_ptr, SL("_values"), &field, &value TSRMLS_CC);
	RETURN_CCTOR(value);

}

/**
 * Internal validations, if it returns true, then skip the current validator
 */
PHP_METHOD(Phalcon_Validation, preChecking) {

	zephir_fcall_cache_entry *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *field, field_sub, *validator, validator_sub, singleField, *_0$$3, _1$$4, _2$$4, _3$$4, _4$$5, _6$$7, _7$$7, _8$$7, _9$$8;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&validator_sub);
	ZVAL_UNDEF(&singleField);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_9$$8);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &field, &validator);



	if (Z_TYPE_P(field) == IS_ARRAY) {
		zephir_is_iterable(field, 0, "phalcon/validation.zep", 576);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(field), _0$$3)
		{
			ZEPHIR_INIT_NVAR(&singleField);
			ZVAL_COPY(&singleField, _0$$3);
			ZEPHIR_INIT_NVAR(&_2$$4);
			ZVAL_STRING(&_2$$4, "allowEmpty");
			ZVAL_BOOL(&_3$$4, 0);
			ZEPHIR_CALL_METHOD(&_1$$4, validator, "getoption", NULL, 0, &_2$$4, &_3$$4);
			zephir_check_call_status();
			if (zephir_is_true(&_1$$4)) {
				if ((zephir_method_exists_ex(validator, SL("isallowempty") TSRMLS_CC) == SUCCESS)) {
					ZEPHIR_RETURN_CALL_METHOD(validator, "isallowempty", NULL, 0, this_ptr, &singleField);
					zephir_check_call_status();
					RETURN_MM();
				}
				ZEPHIR_CALL_METHOD(&_4$$5, this_ptr, "getvalue", &_5, 0, &singleField);
				zephir_check_call_status();
				RETURN_MM_BOOL(ZEPHIR_IS_EMPTY(&_4$$5));
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&singleField);
	} else {
		ZEPHIR_INIT_VAR(&_7$$7);
		ZVAL_STRING(&_7$$7, "allowEmpty");
		ZVAL_BOOL(&_8$$7, 0);
		ZEPHIR_CALL_METHOD(&_6$$7, validator, "getoption", NULL, 0, &_7$$7, &_8$$7);
		zephir_check_call_status();
		if (zephir_is_true(&_6$$7)) {
			if ((zephir_method_exists_ex(validator, SL("isallowempty") TSRMLS_CC) == SUCCESS)) {
				ZEPHIR_RETURN_CALL_METHOD(validator, "isallowempty", NULL, 0, this_ptr, field);
				zephir_check_call_status();
				RETURN_MM();
			}
			ZEPHIR_CALL_METHOD(&_9$$8, this_ptr, "getvalue", &_5, 0, field);
			zephir_check_call_status();
			RETURN_MM_BOOL(ZEPHIR_IS_EMPTY(&_9$$8));
		}
	}
	RETURN_MM_BOOL(0);

}

zend_object *zephir_init_properties_Phalcon_Validation(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("_validators"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("_validators"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

