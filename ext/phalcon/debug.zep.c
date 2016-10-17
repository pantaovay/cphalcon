
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
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/time.h"
#include "kernel/string.h"
#include "kernel/hash.h"
#include "kernel/concat.h"


/**
 * Phalcon\Debug
 *
 * Provides debug capabilities to Phalcon applications
 */
ZEPHIR_INIT_CLASS(Phalcon_Debug) {

	ZEPHIR_REGISTER_CLASS(Phalcon, Debug, phalcon, debug, phalcon_debug_method_entry, 0);

	zend_declare_property_string(phalcon_debug_ce, SL("_uri"), "//static.phalconphp.com/www/debug/3.0.x/", ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_string(phalcon_debug_ce, SL("_theme"), "default", ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_bool(phalcon_debug_ce, SL("_hideDocumentRoot"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(phalcon_debug_ce, SL("_showBackTrace"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(phalcon_debug_ce, SL("_showFiles"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(phalcon_debug_ce, SL("_showFileFragment"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_debug_ce, SL("_data"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_debug_ce, SL("_isActive"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	return SUCCESS;

}

/**
 * Change the base URI for static resources
 */
PHP_METHOD(Phalcon_Debug, setUri) {

	zval *uri_param = NULL;
	zval uri;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&uri);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &uri_param);

	if (unlikely(Z_TYPE_P(uri_param) != IS_STRING && Z_TYPE_P(uri_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'uri' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(uri_param) == IS_STRING)) {
		zephir_get_strval(&uri, uri_param);
	} else {
		ZEPHIR_INIT_VAR(&uri);
		ZVAL_EMPTY_STRING(&uri);
	}


	zephir_update_property_zval(this_ptr, SL("_uri"), &uri);
	RETURN_THIS();

}

/**
 * Sets if files the exception's backtrace must be showed
 */
PHP_METHOD(Phalcon_Debug, setShowBackTrace) {

	zval *showBackTrace_param = NULL, __$true, __$false;
	zend_bool showBackTrace;
	ZEPHIR_INIT_THIS();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);

	zephir_fetch_params(0, 1, 0, &showBackTrace_param);

	showBackTrace = zephir_get_boolval(showBackTrace_param);


	if (showBackTrace) {
		zephir_update_property_zval(this_ptr, SL("_showBackTrace"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("_showBackTrace"), &__$false);
	}
	RETURN_THISW();

}

/**
 * Set if files part of the backtrace must be shown in the output
 */
PHP_METHOD(Phalcon_Debug, setShowFiles) {

	zval *showFiles_param = NULL, __$true, __$false;
	zend_bool showFiles;
	ZEPHIR_INIT_THIS();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);

	zephir_fetch_params(0, 1, 0, &showFiles_param);

	showFiles = zephir_get_boolval(showFiles_param);


	if (showFiles) {
		zephir_update_property_zval(this_ptr, SL("_showFiles"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("_showFiles"), &__$false);
	}
	RETURN_THISW();

}

/**
 * Sets if files must be completely opened and showed in the output
 * or just the fragment related to the exception
 */
PHP_METHOD(Phalcon_Debug, setShowFileFragment) {

	zval *showFileFragment_param = NULL, __$true, __$false;
	zend_bool showFileFragment;
	ZEPHIR_INIT_THIS();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);

	zephir_fetch_params(0, 1, 0, &showFileFragment_param);

	showFileFragment = zephir_get_boolval(showFileFragment_param);


	if (showFileFragment) {
		zephir_update_property_zval(this_ptr, SL("_showFileFragment"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("_showFileFragment"), &__$false);
	}
	RETURN_THISW();

}

/**
 * Listen for uncaught exceptions and unsilent notices or warnings
 */
PHP_METHOD(Phalcon_Debug, listen) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *exceptions_param = NULL, *lowSeverity_param = NULL;
	zend_bool exceptions, lowSeverity;
	ZEPHIR_INIT_THIS();


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &exceptions_param, &lowSeverity_param);

	if (!exceptions_param) {
		exceptions = 1;
	} else {
		exceptions = zephir_get_boolval(exceptions_param);
	}
	if (!lowSeverity_param) {
		lowSeverity = 0;
	} else {
		lowSeverity = zephir_get_boolval(lowSeverity_param);
	}


	if (exceptions) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "listenexceptions", NULL, 0);
		zephir_check_call_status();
	}
	if (lowSeverity) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "listenlowseverity", NULL, 0);
		zephir_check_call_status();
	}
	RETURN_THIS();

}

/**
 * Listen for uncaught exceptions
 */
PHP_METHOD(Phalcon_Debug, listenExceptions) {

	zval _1;
	zval _0;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_0, this_ptr);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "onUncaughtException");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_CALL_FUNCTION(NULL, "set_exception_handler", NULL, 156, &_0);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Listen for unsilent notices or warnings
 */
PHP_METHOD(Phalcon_Debug, listenLowSeverity) {

	zval _1;
	zval _0, _2;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_0, this_ptr);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "onUncaughtLowSeverity");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_CALL_FUNCTION(NULL, "set_error_handler", NULL, 157, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_2, this_ptr);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "onUncaughtException");
	zephir_array_fast_append(&_2, &_1);
	ZEPHIR_CALL_FUNCTION(NULL, "set_exception_handler", NULL, 156, &_2);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Halts the request showing a backtrace
 */
PHP_METHOD(Phalcon_Debug, halt) {

	ZEPHIR_INIT_THIS();


	ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalcon_exception_ce, "Halted request", "phalcon/debug.zep", 120);
	return;

}

/**
 * Adds a variable to the debug output
 */
PHP_METHOD(Phalcon_Debug, debugVar) {

	zval _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval key;
	zval *varz, varz_sub, *key_param = NULL, _1, _2;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&varz_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &varz, &key_param);

	if (!key_param) {
		ZEPHIR_INIT_VAR(&key);
		ZVAL_STRING(&key, "");
	} else {
		zephir_get_strval(&key, key_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 3, 0 TSRMLS_CC);
	zephir_array_fast_append(&_0, varz);
	ZEPHIR_CALL_FUNCTION(&_1, "debug_backtrace", NULL, 158);
	zephir_check_call_status();
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_VAR(&_2);
	zephir_time(&_2);
	zephir_array_fast_append(&_0, &_2);
	zephir_update_property_array_append(this_ptr, SL("_data"), &_0 TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Clears are variables added previously
 */
PHP_METHOD(Phalcon_Debug, clearVars) {

	zval __$null;
	ZEPHIR_INIT_THIS();

	ZVAL_NULL(&__$null);


	zephir_update_property_zval(this_ptr, SL("_data"), &__$null);
	RETURN_THISW();

}

/**
 * Escapes a string with htmlentities
 */
PHP_METHOD(Phalcon_Debug, _escapeString) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *value, value_sub, _0$$3, _1$$3, _2$$3, _3$$3, _4$$3;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value);



	if (Z_TYPE_P(value) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "\n");
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "\\n");
		zephir_fast_str_replace(&_0$$3, &_1$$3, &_2$$3, value TSRMLS_CC);
		ZVAL_LONG(&_3$$3, 2);
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "utf-8");
		ZEPHIR_RETURN_CALL_FUNCTION("htmlentities", NULL, 159, &_0$$3, &_3$$3, &_4$$3);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETVAL_ZVAL(value, 1, 0);
	RETURN_MM();

}

/**
 * Produces a recursive representation of an array
 */
PHP_METHOD(Phalcon_Debug, _getArrayDump) {

	zend_string *_3;
	zend_ulong _2;
	zend_bool _0;
	zephir_fcall_cache_entry *_5 = NULL, *_8 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *argument_param = NULL, *n = NULL, n_sub, numberArguments, dump, varDump, k, v, *_1, _4$$8, _6$$9, _7$$9, _9$$9, _10$$10, _11$$10, _12$$11, _13$$5;
	zval argument;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&argument);
	ZVAL_UNDEF(&n_sub);
	ZVAL_UNDEF(&numberArguments);
	ZVAL_UNDEF(&dump);
	ZVAL_UNDEF(&varDump);
	ZVAL_UNDEF(&k);
	ZVAL_UNDEF(&v);
	ZVAL_UNDEF(&_4$$8);
	ZVAL_UNDEF(&_6$$9);
	ZVAL_UNDEF(&_7$$9);
	ZVAL_UNDEF(&_9$$9);
	ZVAL_UNDEF(&_10$$10);
	ZVAL_UNDEF(&_11$$10);
	ZVAL_UNDEF(&_12$$11);
	ZVAL_UNDEF(&_13$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &argument_param, &n);

	ZEPHIR_OBS_COPY_OR_DUP(&argument, argument_param);
	if (!n) {
		n = &n_sub;
		ZEPHIR_INIT_VAR(n);
		ZVAL_LONG(n, 0);
	}


	ZEPHIR_INIT_VAR(&numberArguments);
	ZVAL_LONG(&numberArguments, zephir_fast_count_int(&argument TSRMLS_CC));
	_0 = ZEPHIR_GE_LONG(n, 3);
	if (!(_0)) {
		_0 = ZEPHIR_IS_LONG(&numberArguments, 0);
	}
	if (_0) {
		RETURN_MM_NULL();
	}
	if (ZEPHIR_GE_LONG(&numberArguments, 10)) {
		RETURN_CCTOR(numberArguments);
	}
	ZEPHIR_INIT_VAR(&dump);
	array_init(&dump);
	zephir_is_iterable(&argument, 0, "phalcon/debug.zep", 200);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&argument), _2, _3, _1)
	{
		ZEPHIR_INIT_NVAR(&k);
		if (_3 != NULL) { 
			ZVAL_STR_COPY(&k, _3);
		} else {
			ZVAL_LONG(&k, _2);
		}
		ZEPHIR_INIT_NVAR(&v);
		ZVAL_COPY(&v, _1);
		if (zephir_is_scalar(&v)) {
			ZEPHIR_INIT_NVAR(&varDump);
			if (ZEPHIR_IS_STRING(&v, "")) {
				ZEPHIR_CONCAT_SVS(&varDump, "[", &k, "] =&gt; (empty string)");
			} else {
				ZEPHIR_CALL_METHOD(&_4$$8, this_ptr, "_escapestring", &_5, 0, &v);
				zephir_check_call_status();
				ZEPHIR_CONCAT_SVSV(&varDump, "[", &k, "] =&gt; ", &_4$$8);
			}
			zephir_array_append(&dump, &varDump, PH_SEPARATE, "phalcon/debug.zep", 178);
			continue;
		}
		if (Z_TYPE_P(&v) == IS_ARRAY) {
			ZVAL_LONG(&_7$$9, (zephir_get_numberval(n) + 1));
			ZEPHIR_CALL_METHOD(&_6$$9, this_ptr, "_getarraydump", &_8, 160, &v, &_7$$9);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_9$$9);
			ZEPHIR_CONCAT_SVSVS(&_9$$9, "[", &k, "] =&gt; Array(", &_6$$9, ")");
			zephir_array_append(&dump, &_9$$9, PH_SEPARATE, "phalcon/debug.zep", 183);
			continue;
		}
		if (Z_TYPE_P(&v) == IS_OBJECT) {
			ZEPHIR_INIT_NVAR(&_10$$10);
			zephir_get_class(&_10$$10, &v, 0 TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_11$$10);
			ZEPHIR_CONCAT_SVSVS(&_11$$10, "[", &k, "] =&gt; Object(", &_10$$10, ")");
			zephir_array_append(&dump, &_11$$10, PH_SEPARATE, "phalcon/debug.zep", 188);
			continue;
		}
		if (Z_TYPE_P(&v) == IS_NULL) {
			ZEPHIR_INIT_LNVAR(_12$$11);
			ZEPHIR_CONCAT_SVS(&_12$$11, "[", &k, "] =&gt; null");
			zephir_array_append(&dump, &_12$$11, PH_SEPARATE, "phalcon/debug.zep", 193);
			continue;
		}
		ZEPHIR_INIT_LNVAR(_13$$5);
		ZEPHIR_CONCAT_SVSV(&_13$$5, "[", &k, "] =&gt; ", &v);
		zephir_array_append(&dump, &_13$$5, PH_SEPARATE, "phalcon/debug.zep", 197);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&v);
	ZEPHIR_INIT_NVAR(&k);
	zephir_fast_join_str(return_value, SL(", "), &dump TSRMLS_CC);
	RETURN_MM();

}

/**
 * Produces an string representation of a variable
 */
PHP_METHOD(Phalcon_Debug, _getVarDump) {

	zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *variable, variable_sub, className, dumpedObject, _0$$9, _2$$11;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&variable_sub);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&dumpedObject);
	ZVAL_UNDEF(&_0$$9);
	ZVAL_UNDEF(&_2$$11);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &variable);



	if (zephir_is_scalar(variable)) {
		if (((Z_TYPE_P(variable) == IS_TRUE || Z_TYPE_P(variable) == IS_FALSE) == 1)) {
			if (zephir_is_true(variable)) {
				RETURN_MM_STRING("true");
			} else {
				RETURN_MM_STRING("false");
			}
		}
		if (Z_TYPE_P(variable) == IS_STRING) {
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_escapestring", NULL, 0, variable);
			zephir_check_call_status();
			RETURN_MM();
		}
		RETVAL_ZVAL(variable, 1, 0);
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&className);
		zephir_get_class(&className, variable, 0 TSRMLS_CC);
		if ((zephir_method_exists_ex(variable, SL("dump") TSRMLS_CC) == SUCCESS)) {
			ZEPHIR_CALL_METHOD(&dumpedObject, variable, "dump", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_0$$9, this_ptr, "_getarraydump", &_1, 0, &dumpedObject);
			zephir_check_call_status();
			ZEPHIR_CONCAT_SVSVS(return_value, "Object(", &className, ": ", &_0$$9, ")");
			RETURN_MM();
		} else {
			ZEPHIR_CONCAT_SVS(return_value, "Object(", &className, ")");
			RETURN_MM();
		}
	}
	if (Z_TYPE_P(variable) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(&_2$$11, this_ptr, "_getarraydump", &_1, 160, variable);
		zephir_check_call_status();
		ZEPHIR_CONCAT_SVS(return_value, "Array(", &_2$$11, ")");
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_NULL) {
		RETURN_MM_STRING("null");
	}
	zephir_gettype(return_value, variable TSRMLS_CC);
	RETURN_MM();

}

/**
 * Returns the major framework's version
 */
PHP_METHOD(Phalcon_Debug, getMajorVersion) {

	zval parts, _0, _2;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&parts);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_CE_STATIC(&_0, phalcon_version_ce, "get", &_1, 161);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&parts);
	zephir_fast_explode_str(&parts, SL(" "), &_0, LONG_MAX TSRMLS_CC);
	zephir_array_fetch_long(&_2, &parts, 0, PH_NOISY | PH_READONLY, "phalcon/debug.zep", 289 TSRMLS_CC);
	RETURN_CTOR(_2);

}

/**
 * Generates a link to the current version documentation
 */
PHP_METHOD(Phalcon_Debug, getVersion) {

	zval _0, _1;
	zephir_fcall_cache_entry *_2 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmajorversion", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&_1, phalcon_version_ce, "get", &_2, 161);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVSVS(return_value, "<div class=\"version\">Phalcon Framework <a target=\"_new\" href=\"//docs.phalconphp.com/en/", &_0, "/\">", &_1, "</a></div>");
	RETURN_MM();

}

/**
 * Returns the css sources
 */
PHP_METHOD(Phalcon_Debug, getCssSources) {

	zval uri, sources, _0, _1;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&uri);
	ZVAL_UNDEF(&sources);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	zephir_read_property(&uri, this_ptr, SL("_uri"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&sources);
	ZEPHIR_CONCAT_SVS(&sources, "<link href=\"", &uri, "bower_components/jquery-ui/themes/ui-lightness/jquery-ui.min.css\" type=\"text/css\" rel=\"stylesheet\" />");
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_SVS(&_0, "<link href=\"", &uri, "bower_components/jquery-ui/themes/ui-lightness/theme.css\" type=\"text/css\" rel=\"stylesheet\" />");
	zephir_concat_self(&sources, &_0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_SVS(&_1, "<link href=\"", &uri, "themes/default/style.css\" type=\"text/css\" rel=\"stylesheet\" />");
	zephir_concat_self(&sources, &_1 TSRMLS_CC);
	RETURN_CCTOR(sources);

}

/**
 * Returns the javascript sources
 */
PHP_METHOD(Phalcon_Debug, getJsSources) {

	zval uri, sources, _0, _1, _2, _3;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&uri);
	ZVAL_UNDEF(&sources);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();

	zephir_read_property(&uri, this_ptr, SL("_uri"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&sources);
	ZEPHIR_CONCAT_SVS(&sources, "<script type=\"text/javascript\" src=\"", &uri, "bower_components/jquery/dist/jquery.min.js\"></script>");
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_SVS(&_0, "<script type=\"text/javascript\" src=\"", &uri, "bower_components/jquery-ui/jquery-ui.min.js\"></script>");
	zephir_concat_self(&sources, &_0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_SVS(&_1, "<script type=\"text/javascript\" src=\"", &uri, "bower_components/jquery.scrollTo/jquery.scrollTo.min.js\"></script>");
	zephir_concat_self(&sources, &_1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_SVS(&_2, "<script type=\"text/javascript\" src=\"", &uri, "prettify/prettify.js\"></script>");
	zephir_concat_self(&sources, &_2 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CONCAT_SVS(&_3, "<script type=\"text/javascript\" src=\"", &uri, "pretty.js\"></script>");
	zephir_concat_self(&sources, &_3 TSRMLS_CC);
	RETURN_CCTOR(sources);

}

/**
 * Shows a backtrace item
 */
PHP_METHOD(Phalcon_Debug, showTraceItem) {

	zend_bool _43$$26;
	zval _1, _29$$18;
	zephir_fcall_cache_entry *_24 = NULL, *_50 = NULL;
	zval trace;
	zval *n_param = NULL, *trace_param = NULL, className, prepareInternalClass, preparedFunctionName, html, classReflection, prepareUriClass, functionName, functionReflection, traceArgs, arguments, argument, filez, line, showFiles, lines, numberLines, showFileFragment, beforeLine, afterLine, lastLine, linePosition, currentLine, _0, _2$$3, _3$$3, _4$$3, _14$$3, _5$$4, _6$$4, _7$$4, _8$$5, _9$$6, _10$$6, _11$$6, _12$$6, _13$$7, _15$$8, _16$$10, _17$$11, _18$$11, _19$$11, _20$$12, _21$$13, *_22$$15, _26$$15, _27$$15, _23$$16, _25$$16, _28$$18, _30$$18, _31$$20, _32$$20, _33$$20, _34$$25, _35$$25, _36$$28, _37$$28, _38$$28, _39$$28, _40$$29, _41$$29, _42$$29, _44$$31, _45$$31, _46$$31, _47$$31, _48$$31, _49$$31;
	int n, ZEPHIR_LAST_CALL_STATUS, firstLine = 0, i = 0;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&prepareInternalClass);
	ZVAL_UNDEF(&preparedFunctionName);
	ZVAL_UNDEF(&html);
	ZVAL_UNDEF(&classReflection);
	ZVAL_UNDEF(&prepareUriClass);
	ZVAL_UNDEF(&functionName);
	ZVAL_UNDEF(&functionReflection);
	ZVAL_UNDEF(&traceArgs);
	ZVAL_UNDEF(&arguments);
	ZVAL_UNDEF(&argument);
	ZVAL_UNDEF(&filez);
	ZVAL_UNDEF(&line);
	ZVAL_UNDEF(&showFiles);
	ZVAL_UNDEF(&lines);
	ZVAL_UNDEF(&numberLines);
	ZVAL_UNDEF(&showFileFragment);
	ZVAL_UNDEF(&beforeLine);
	ZVAL_UNDEF(&afterLine);
	ZVAL_UNDEF(&lastLine);
	ZVAL_UNDEF(&linePosition);
	ZVAL_UNDEF(&currentLine);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_14$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_15$$8);
	ZVAL_UNDEF(&_16$$10);
	ZVAL_UNDEF(&_17$$11);
	ZVAL_UNDEF(&_18$$11);
	ZVAL_UNDEF(&_19$$11);
	ZVAL_UNDEF(&_20$$12);
	ZVAL_UNDEF(&_21$$13);
	ZVAL_UNDEF(&_26$$15);
	ZVAL_UNDEF(&_27$$15);
	ZVAL_UNDEF(&_23$$16);
	ZVAL_UNDEF(&_25$$16);
	ZVAL_UNDEF(&_28$$18);
	ZVAL_UNDEF(&_30$$18);
	ZVAL_UNDEF(&_31$$20);
	ZVAL_UNDEF(&_32$$20);
	ZVAL_UNDEF(&_33$$20);
	ZVAL_UNDEF(&_34$$25);
	ZVAL_UNDEF(&_35$$25);
	ZVAL_UNDEF(&_36$$28);
	ZVAL_UNDEF(&_37$$28);
	ZVAL_UNDEF(&_38$$28);
	ZVAL_UNDEF(&_39$$28);
	ZVAL_UNDEF(&_40$$29);
	ZVAL_UNDEF(&_41$$29);
	ZVAL_UNDEF(&_42$$29);
	ZVAL_UNDEF(&_44$$31);
	ZVAL_UNDEF(&_45$$31);
	ZVAL_UNDEF(&_46$$31);
	ZVAL_UNDEF(&_47$$31);
	ZVAL_UNDEF(&_48$$31);
	ZVAL_UNDEF(&_49$$31);
	ZVAL_UNDEF(&trace);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_29$$18);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &n_param, &trace_param);

	n = zephir_get_intval(n_param);
	ZEPHIR_OBS_COPY_OR_DUP(&trace, trace_param);


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, n);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_SVS(&_1, "<tr><td align=\"right\" valign=\"top\" class=\"error-number\">#", &_0, "</td><td>");
	ZEPHIR_CPY_WRT(&html, &_1);
	ZEPHIR_OBS_VAR(&className);
	if (zephir_array_isset_string_fetch(&className, &trace, SL("class"), 0)) {
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_INIT_VAR(&_3$$3);
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "/^Phalcon/");
		zephir_preg_match(&_3$$3, &_4$$3, &className, &_2$$3, 0, 0 , 0  TSRMLS_CC);
		if (zephir_is_true(&_3$$3)) {
			ZEPHIR_INIT_VAR(&_5$$4);
			ZVAL_STRING(&_5$$4, "\\");
			ZEPHIR_INIT_VAR(&_6$$4);
			ZVAL_STRING(&_6$$4, "/");
			ZEPHIR_INIT_VAR(&prepareUriClass);
			zephir_fast_str_replace(&prepareUriClass, &_5$$4, &_6$$4, &className TSRMLS_CC);
			ZEPHIR_INIT_VAR(&_7$$4);
			ZEPHIR_CONCAT_SVSVS(&_7$$4, "<span class=\"error-class\"><a target=\"_new\" href=\"//api.phalconphp.com/class/", &prepareUriClass, ".html\">", &className, "</a></span>");
			zephir_concat_self(&html, &_7$$4 TSRMLS_CC);
		} else {
			ZEPHIR_INIT_VAR(&classReflection);
			object_init_ex(&classReflection, zephir_get_internal_ce(SL("reflectionclass")));
			ZEPHIR_CALL_METHOD(NULL, &classReflection, "__construct", NULL, 94, &className);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_8$$5, &classReflection, "isinternal", NULL, 162);
			zephir_check_call_status();
			if (zephir_is_true(&_8$$5)) {
				ZEPHIR_INIT_VAR(&_9$$6);
				zephir_fast_strtolower(&_9$$6, &className);
				ZEPHIR_INIT_VAR(&_10$$6);
				ZVAL_STRING(&_10$$6, "_");
				ZEPHIR_INIT_VAR(&_11$$6);
				ZVAL_STRING(&_11$$6, "-");
				ZEPHIR_INIT_VAR(&prepareInternalClass);
				zephir_fast_str_replace(&prepareInternalClass, &_10$$6, &_11$$6, &_9$$6 TSRMLS_CC);
				ZEPHIR_INIT_VAR(&_12$$6);
				ZEPHIR_CONCAT_SVSVS(&_12$$6, "<span class=\"error-class\"><a target=\"_new\" href=\"http://php.net/manual/en/class.", &prepareInternalClass, ".php\">", &className, "</a></span>");
				zephir_concat_self(&html, &_12$$6 TSRMLS_CC);
			} else {
				ZEPHIR_INIT_VAR(&_13$$7);
				ZEPHIR_CONCAT_SVS(&_13$$7, "<span class=\"error-class\">", &className, "</span>");
				zephir_concat_self(&html, &_13$$7 TSRMLS_CC);
			}
		}
		zephir_array_fetch_string(&_14$$3, &trace, SL("type"), PH_NOISY | PH_READONLY, "phalcon/debug.zep", 386 TSRMLS_CC);
		zephir_concat_self(&html, &_14$$3 TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(&functionName);
	zephir_array_fetch_string(&functionName, &trace, SL("function"), PH_NOISY, "phalcon/debug.zep", 392 TSRMLS_CC);
	if (zephir_array_isset_string(&trace, SL("class"))) {
		ZEPHIR_INIT_VAR(&_15$$8);
		ZEPHIR_CONCAT_SVS(&_15$$8, "<span class=\"error-function\">", &functionName, "</span>");
		zephir_concat_self(&html, &_15$$8 TSRMLS_CC);
	} else {
		if ((zephir_function_exists(&functionName TSRMLS_CC)  == SUCCESS)) {
			ZEPHIR_INIT_VAR(&functionReflection);
			object_init_ex(&functionReflection, zephir_get_internal_ce(SL("reflectionfunction")));
			ZEPHIR_CALL_METHOD(NULL, &functionReflection, "__construct", NULL, 85, &functionName);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_16$$10, &functionReflection, "isinternal", NULL, 163);
			zephir_check_call_status();
			if (zephir_is_true(&_16$$10)) {
				ZEPHIR_INIT_VAR(&_17$$11);
				ZVAL_STRING(&_17$$11, "_");
				ZEPHIR_INIT_VAR(&_18$$11);
				ZVAL_STRING(&_18$$11, "-");
				ZEPHIR_INIT_VAR(&preparedFunctionName);
				zephir_fast_str_replace(&preparedFunctionName, &_17$$11, &_18$$11, &functionName TSRMLS_CC);
				ZEPHIR_INIT_VAR(&_19$$11);
				ZEPHIR_CONCAT_SVSVS(&_19$$11, "<span class=\"error-function\"><a target=\"_new\" href=\"http://php.net/manual/en/function.", &preparedFunctionName, ".php\">", &functionName, "</a></span>");
				zephir_concat_self(&html, &_19$$11 TSRMLS_CC);
			} else {
				ZEPHIR_INIT_VAR(&_20$$12);
				ZEPHIR_CONCAT_SVS(&_20$$12, "<span class=\"error-function\">", &functionName, "</span>");
				zephir_concat_self(&html, &_20$$12 TSRMLS_CC);
			}
		} else {
			ZEPHIR_INIT_VAR(&_21$$13);
			ZEPHIR_CONCAT_SVS(&_21$$13, "<span class=\"error-function\">", &functionName, "</span>");
			zephir_concat_self(&html, &_21$$13 TSRMLS_CC);
		}
	}
	ZEPHIR_OBS_VAR(&traceArgs);
	if (zephir_array_isset_string_fetch(&traceArgs, &trace, SL("args"), 0)) {
		if (zephir_fast_count_int(&traceArgs TSRMLS_CC)) {
			ZEPHIR_INIT_VAR(&arguments);
			array_init(&arguments);
			zephir_is_iterable(&traceArgs, 0, "phalcon/debug.zep", 440);
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&traceArgs), _22$$15)
			{
				ZEPHIR_INIT_NVAR(&argument);
				ZVAL_COPY(&argument, _22$$15);
				ZEPHIR_CALL_METHOD(&_23$$16, this_ptr, "_getvardump", &_24, 0, &argument);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_25$$16);
				ZEPHIR_CONCAT_SVS(&_25$$16, "<span class=\"error-parameter\">", &_23$$16, "</span>");
				zephir_array_append(&arguments, &_25$$16, PH_SEPARATE, "phalcon/debug.zep", 434);
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&argument);
			ZEPHIR_INIT_VAR(&_26$$15);
			zephir_fast_join_str(&_26$$15, SL(", "), &arguments TSRMLS_CC);
			ZEPHIR_INIT_VAR(&_27$$15);
			ZEPHIR_CONCAT_SVS(&_27$$15, "(", &_26$$15, ")");
			zephir_concat_self(&html, &_27$$15 TSRMLS_CC);
		} else {
			zephir_concat_self_str(&html, SL("()") TSRMLS_CC);
		}
	}
	ZEPHIR_OBS_VAR(&filez);
	if (zephir_array_isset_string_fetch(&filez, &trace, SL("file"), 0)) {
		ZEPHIR_OBS_VAR(&_28$$18);
		zephir_array_fetch_string(&_28$$18, &trace, SL("line"), PH_NOISY, "phalcon/debug.zep", 451 TSRMLS_CC);
		zephir_get_strval(&_29$$18, &_28$$18);
		ZEPHIR_CPY_WRT(&line, &_29$$18);
		ZEPHIR_INIT_VAR(&_30$$18);
		ZEPHIR_CONCAT_SVSVS(&_30$$18, "<br/><div class=\"error-file\">", &filez, " (", &line, ")</div>");
		zephir_concat_self(&html, &_30$$18 TSRMLS_CC);
		ZEPHIR_OBS_VAR(&showFiles);
		zephir_read_property(&showFiles, this_ptr, SL("_showFiles"), PH_NOISY_CC);
		if (zephir_is_true(&showFiles)) {
			ZEPHIR_CALL_FUNCTION(&lines, "file", NULL, 164, &filez);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&numberLines);
			ZVAL_LONG(&numberLines, zephir_fast_count_int(&lines TSRMLS_CC));
			ZEPHIR_OBS_VAR(&showFileFragment);
			zephir_read_property(&showFileFragment, this_ptr, SL("_showFileFragment"), PH_NOISY_CC);
			if (zephir_is_true(&showFileFragment)) {
				ZEPHIR_INIT_VAR(&beforeLine);
				ZVAL_LONG(&beforeLine, (zephir_get_numberval(&line) - 7));
				if (ZEPHIR_LT_LONG(&beforeLine, 1)) {
					firstLine = 1;
				} else {
					firstLine = zephir_get_numberval(&beforeLine);
				}
				ZEPHIR_INIT_VAR(&afterLine);
				ZVAL_LONG(&afterLine, (zephir_get_numberval(&line) + 5));
				if (ZEPHIR_GT(&afterLine, &numberLines)) {
					ZEPHIR_CPY_WRT(&lastLine, &numberLines);
				} else {
					ZEPHIR_CPY_WRT(&lastLine, &afterLine);
				}
				ZEPHIR_SINIT_VAR(_31$$20);
				ZVAL_LONG(&_31$$20, firstLine);
				ZEPHIR_SINIT_VAR(_32$$20);
				ZVAL_LONG(&_32$$20, firstLine);
				ZEPHIR_INIT_VAR(&_33$$20);
				ZEPHIR_CONCAT_SVSVSVS(&_33$$20, "<pre class=\"prettyprint highlight:", &_31$$20, ":", &line, " linenums:", &_32$$20, "\">");
				zephir_concat_self(&html, &_33$$20 TSRMLS_CC);
			} else {
				firstLine = 1;
				ZEPHIR_CPY_WRT(&lastLine, &numberLines);
				ZEPHIR_SINIT_VAR(_34$$25);
				ZVAL_LONG(&_34$$25, firstLine);
				ZEPHIR_INIT_VAR(&_35$$25);
				ZEPHIR_CONCAT_SVSVS(&_35$$25, "<pre class=\"prettyprint highlight:", &_34$$25, ":", &line, " linenums error-scroll\">");
				zephir_concat_self(&html, &_35$$25 TSRMLS_CC);
			}
			i = firstLine;
			while (1) {
				if (!(ZEPHIR_GE_LONG(&lastLine, i))) {
					break;
				}
				ZEPHIR_INIT_NVAR(&linePosition);
				ZVAL_LONG(&linePosition, (i - 1));
				ZEPHIR_OBS_NVAR(&currentLine);
				zephir_array_fetch(&currentLine, &lines, &linePosition, PH_NOISY, "phalcon/debug.zep", 524 TSRMLS_CC);
				if (zephir_is_true(&showFileFragment)) {
					if (i == firstLine) {
						ZEPHIR_INIT_NVAR(&_36$$28);
						ZEPHIR_INIT_NVAR(&_37$$28);
						ZEPHIR_INIT_NVAR(&_38$$28);
						zephir_fast_trim(&_38$$28, &currentLine, NULL , ZEPHIR_TRIM_RIGHT TSRMLS_CC);
						ZEPHIR_INIT_NVAR(&_39$$28);
						ZVAL_STRING(&_39$$28, "#\\*\\/#");
						zephir_preg_match(&_37$$28, &_39$$28, &_38$$28, &_36$$28, 0, 0 , 0  TSRMLS_CC);
						if (zephir_is_true(&_37$$28)) {
							ZEPHIR_INIT_NVAR(&_40$$29);
							ZEPHIR_INIT_NVAR(&_41$$29);
							ZVAL_STRING(&_41$$29, "* /");
							ZEPHIR_INIT_NVAR(&_42$$29);
							ZVAL_STRING(&_42$$29, " ");
							zephir_fast_str_replace(&_40$$29, &_41$$29, &_42$$29, &currentLine TSRMLS_CC);
							ZEPHIR_CPY_WRT(&currentLine, &_40$$29);
						}
					}
				}
				_43$$26 = ZEPHIR_IS_STRING(&currentLine, "\n");
				if (!(_43$$26)) {
					_43$$26 = ZEPHIR_IS_STRING(&currentLine, "\r\n");
				}
				if (_43$$26) {
					zephir_concat_self_str(&html, SL("&nbsp;\n") TSRMLS_CC);
				} else {
					ZEPHIR_INIT_NVAR(&_44$$31);
					ZEPHIR_INIT_NVAR(&_45$$31);
					ZVAL_STRING(&_45$$31, "\t");
					ZEPHIR_INIT_NVAR(&_46$$31);
					ZVAL_STRING(&_46$$31, "  ");
					zephir_fast_str_replace(&_44$$31, &_45$$31, &_46$$31, &currentLine TSRMLS_CC);
					ZVAL_LONG(&_47$$31, 2);
					ZEPHIR_INIT_NVAR(&_48$$31);
					ZVAL_STRING(&_48$$31, "UTF-8");
					ZEPHIR_CALL_FUNCTION(&_49$$31, "htmlentities", &_50, 159, &_44$$31, &_47$$31, &_48$$31);
					zephir_check_call_status();
					zephir_concat_self(&html, &_49$$31 TSRMLS_CC);
				}
				i++;
			}
			zephir_concat_self_str(&html, SL("</pre>") TSRMLS_CC);
		}
	}
	zephir_concat_self_str(&html, SL("</td></tr>") TSRMLS_CC);
	RETURN_CCTOR(html);

}

/**
 * Throws an exception when a notice or warning is raised
 */
PHP_METHOD(Phalcon_Debug, onUncaughtLowSeverity) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *severity, severity_sub, *message, message_sub, *file, file_sub, *line, line_sub, *context, context_sub, _0, _1, _2$$3, _3$$3;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&severity_sub);
	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&file_sub);
	ZVAL_UNDEF(&line_sub);
	ZVAL_UNDEF(&context_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 5, 0, &severity, &message, &file, &line, &context);



	ZEPHIR_CALL_FUNCTION(&_0, "error_reporting", NULL, 165);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_1);
	zephir_bitwise_and_function(&_1, &_0, severity TSRMLS_CC);
	if (zephir_is_true(&_1)) {
		ZEPHIR_INIT_VAR(&_2$$3);
		object_init_ex(&_2$$3, zephir_get_internal_ce(SL("errorexception")));
		ZVAL_LONG(&_3$$3, 0);
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "__construct", NULL, 166, message, &_3$$3, severity, file, line);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$3, "phalcon/debug.zep", 567 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Handles uncaught exceptions
 */
PHP_METHOD(Phalcon_Debug, onUncaughtException) {

	zend_string *_13$$5, *_18$$5, *_25$$5, *_32$$5, *_38$$13;
	zend_ulong _12$$5, _17$$5, _24$$5, _31$$5, _37$$13;
	zephir_fcall_cache_entry *_15 = NULL, *_21 = NULL, *_27 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *exception, exception_sub, __$true, _REQUEST, _SERVER, __$false, obLevel, className, escapedMessage, html, showBackTrace, dataVars, n, traceItem, keyRequest, value, keyServer, keyFile, keyVar, dataVar, _0, _2, _3, _4, _5, _6, _7, _8, _9, _42, _43, _1$$4, _10$$5, *_11$$5, *_16$$5, *_23$$5, _29$$5, *_30$$5, _34$$5, _35$$5, _14$$7, _19$$9, _20$$10, _22$$10, _26$$11, _28$$11, _33$$12, *_36$$13, _39$$14, _40$$14, _41$$14;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&exception_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_REQUEST);
	ZVAL_UNDEF(&_SERVER);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&obLevel);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&escapedMessage);
	ZVAL_UNDEF(&html);
	ZVAL_UNDEF(&showBackTrace);
	ZVAL_UNDEF(&dataVars);
	ZVAL_UNDEF(&n);
	ZVAL_UNDEF(&traceItem);
	ZVAL_UNDEF(&keyRequest);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&keyServer);
	ZVAL_UNDEF(&keyFile);
	ZVAL_UNDEF(&keyVar);
	ZVAL_UNDEF(&dataVar);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_42);
	ZVAL_UNDEF(&_43);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_29$$5);
	ZVAL_UNDEF(&_34$$5);
	ZVAL_UNDEF(&_35$$5);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_19$$9);
	ZVAL_UNDEF(&_20$$10);
	ZVAL_UNDEF(&_22$$10);
	ZVAL_UNDEF(&_26$$11);
	ZVAL_UNDEF(&_28$$11);
	ZVAL_UNDEF(&_33$$12);
	ZVAL_UNDEF(&_39$$14);
	ZVAL_UNDEF(&_40$$14);
	ZVAL_UNDEF(&_41$$14);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SL("_SERVER"));
	zephir_get_global(&_REQUEST, SL("_REQUEST"));
	zephir_fetch_params(1, 1, 0, &exception);



	ZEPHIR_CALL_FUNCTION(&obLevel, "ob_get_level", NULL, 167);
	zephir_check_call_status();
	if (ZEPHIR_GT_LONG(&obLevel, 0)) {
		ZEPHIR_CALL_FUNCTION(NULL, "ob_end_clean", NULL, 129);
		zephir_check_call_status();
	}
	zephir_read_static_property_ce(&_0, phalcon_debug_ce, SL("_isActive"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		ZEPHIR_CALL_METHOD(&_1$$4, exception, "getmessage", NULL, 0);
		zephir_check_call_status();
		zend_print_zval(&_1$$4, 0);
		RETURN_MM_NULL();
	}
	zephir_update_static_property_ce(phalcon_debug_ce, SL("_isActive"), &__$true);
	ZEPHIR_INIT_VAR(&className);
	zephir_get_class(&className, exception, 0 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_2, exception, "getmessage", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&escapedMessage, this_ptr, "_escapestring", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&html);
	ZEPHIR_CONCAT_SVSVS(&html, "<html><head><title>", &className, ": ", &escapedMessage, "</title>");
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "getcsssources", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_VS(&_4, &_3, "</head><body>");
	zephir_concat_self(&html, &_4 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "getversion", NULL, 0);
	zephir_check_call_status();
	zephir_concat_self(&html, &_5 TSRMLS_CC);
	zephir_concat_self_str(&html, SL("<div align=\"center\"><div class=\"error-main\">") TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_6);
	ZEPHIR_CONCAT_SVSVS(&_6, "<h1>", &className, ": ", &escapedMessage, "</h1>");
	zephir_concat_self(&html, &_6 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_7, exception, "getfile", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_8, exception, "getline", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_9);
	ZEPHIR_CONCAT_SVSVS(&_9, "<span class=\"error-file\">", &_7, " (", &_8, ")</span>");
	zephir_concat_self(&html, &_9 TSRMLS_CC);
	zephir_concat_self_str(&html, SL("</div>") TSRMLS_CC);
	ZEPHIR_OBS_VAR(&showBackTrace);
	zephir_read_property(&showBackTrace, this_ptr, SL("_showBackTrace"), PH_NOISY_CC);
	if (zephir_is_true(&showBackTrace)) {
		ZEPHIR_OBS_VAR(&dataVars);
		zephir_read_property(&dataVars, this_ptr, SL("_data"), PH_NOISY_CC);
		zephir_concat_self_str(&html, SL("<div class=\"error-info\"><div id=\"tabs\"><ul>") TSRMLS_CC);
		zephir_concat_self_str(&html, SL("<li><a href=\"#error-tabs-1\">Backtrace</a></li>") TSRMLS_CC);
		zephir_concat_self_str(&html, SL("<li><a href=\"#error-tabs-2\">Request</a></li>") TSRMLS_CC);
		zephir_concat_self_str(&html, SL("<li><a href=\"#error-tabs-3\">Server</a></li>") TSRMLS_CC);
		zephir_concat_self_str(&html, SL("<li><a href=\"#error-tabs-4\">Included Files</a></li>") TSRMLS_CC);
		zephir_concat_self_str(&html, SL("<li><a href=\"#error-tabs-5\">Memory</a></li>") TSRMLS_CC);
		if (Z_TYPE_P(&dataVars) == IS_ARRAY) {
			zephir_concat_self_str(&html, SL("<li><a href=\"#error-tabs-6\">Variables</a></li>") TSRMLS_CC);
		}
		zephir_concat_self_str(&html, SL("</ul>") TSRMLS_CC);
		zephir_concat_self_str(&html, SL("<div id=\"error-tabs-1\"><table cellspacing=\"0\" align=\"center\" width=\"100%\">") TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&_10$$5, exception, "gettrace", NULL, 0);
		zephir_check_call_status();
		zephir_is_iterable(&_10$$5, 0, "phalcon/debug.zep", 661);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_10$$5), _12$$5, _13$$5, _11$$5)
		{
			ZEPHIR_INIT_NVAR(&n);
			if (_13$$5 != NULL) { 
				ZVAL_STR_COPY(&n, _13$$5);
			} else {
				ZVAL_LONG(&n, _12$$5);
			}
			ZEPHIR_INIT_NVAR(&traceItem);
			ZVAL_COPY(&traceItem, _11$$5);
			ZEPHIR_CALL_METHOD(&_14$$7, this_ptr, "showtraceitem", &_15, 168, &n, &traceItem);
			zephir_check_call_status();
			zephir_concat_self(&html, &_14$$7 TSRMLS_CC);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&traceItem);
		ZEPHIR_INIT_NVAR(&n);
		zephir_concat_self_str(&html, SL("</table></div>") TSRMLS_CC);
		zephir_concat_self_str(&html, SL("<div id=\"error-tabs-2\"><table cellspacing=\"0\" align=\"center\" class=\"superglobal-detail\">") TSRMLS_CC);
		zephir_concat_self_str(&html, SL("<tr><th>Key</th><th>Value</th></tr>") TSRMLS_CC);
		zephir_is_iterable(&_REQUEST, 0, "phalcon/debug.zep", 675);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_REQUEST), _17$$5, _18$$5, _16$$5)
		{
			ZEPHIR_INIT_NVAR(&keyRequest);
			if (_18$$5 != NULL) { 
				ZVAL_STR_COPY(&keyRequest, _18$$5);
			} else {
				ZVAL_LONG(&keyRequest, _17$$5);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _16$$5);
			if (Z_TYPE_P(&value) != IS_ARRAY) {
				ZEPHIR_INIT_LNVAR(_19$$9);
				ZEPHIR_CONCAT_SVSVS(&_19$$9, "<tr><td class=\"key\">", &keyRequest, "</td><td>", &value, "</td></tr>");
				zephir_concat_self(&html, &_19$$9 TSRMLS_CC);
			} else {
				ZEPHIR_CALL_FUNCTION(&_20$$10, "print_r", &_21, 169, &value, &__$true);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_22$$10);
				ZEPHIR_CONCAT_SVSVS(&_22$$10, "<tr><td class=\"key\">", &keyRequest, "</td><td>", &_20$$10, "</td></tr>");
				zephir_concat_self(&html, &_22$$10 TSRMLS_CC);
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&keyRequest);
		zephir_concat_self_str(&html, SL("</table></div>") TSRMLS_CC);
		zephir_concat_self_str(&html, SL("<div id=\"error-tabs-3\"><table cellspacing=\"0\" align=\"center\" class=\"superglobal-detail\">") TSRMLS_CC);
		zephir_concat_self_str(&html, SL("<tr><th>Key</th><th>Value</th></tr>") TSRMLS_CC);
		zephir_is_iterable(&_SERVER, 0, "phalcon/debug.zep", 685);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_SERVER), _24$$5, _25$$5, _23$$5)
		{
			ZEPHIR_INIT_NVAR(&keyServer);
			if (_25$$5 != NULL) { 
				ZVAL_STR_COPY(&keyServer, _25$$5);
			} else {
				ZVAL_LONG(&keyServer, _24$$5);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _23$$5);
			ZEPHIR_CALL_METHOD(&_26$$11, this_ptr, "_getvardump", &_27, 0, &value);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_28$$11);
			ZEPHIR_CONCAT_SVSVS(&_28$$11, "<tr><td class=\"key\">", &keyServer, "</td><td>", &_26$$11, "</td></tr>");
			zephir_concat_self(&html, &_28$$11 TSRMLS_CC);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&keyServer);
		zephir_concat_self_str(&html, SL("</table></div>") TSRMLS_CC);
		zephir_concat_self_str(&html, SL("<div id=\"error-tabs-4\"><table cellspacing=\"0\" align=\"center\" class=\"superglobal-detail\">") TSRMLS_CC);
		zephir_concat_self_str(&html, SL("<tr><th>#</th><th>Path</th></tr>") TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_29$$5, "get_included_files", NULL, 170);
		zephir_check_call_status();
		zephir_is_iterable(&_29$$5, 0, "phalcon/debug.zep", 695);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_29$$5), _31$$5, _32$$5, _30$$5)
		{
			ZEPHIR_INIT_NVAR(&keyFile);
			if (_32$$5 != NULL) { 
				ZVAL_STR_COPY(&keyFile, _32$$5);
			} else {
				ZVAL_LONG(&keyFile, _31$$5);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _30$$5);
			ZEPHIR_INIT_LNVAR(_33$$12);
			ZEPHIR_CONCAT_SVSVS(&_33$$12, "<tr><td>", &keyFile, "</th><td>", &value, "</td></tr>");
			zephir_concat_self(&html, &_33$$12 TSRMLS_CC);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&keyFile);
		zephir_concat_self_str(&html, SL("</table></div>") TSRMLS_CC);
		zephir_concat_self_str(&html, SL("<div id=\"error-tabs-5\"><table cellspacing=\"0\" align=\"center\" class=\"superglobal-detail\">") TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_34$$5, "memory_get_usage", NULL, 171, &__$true);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_35$$5);
		ZEPHIR_CONCAT_SVS(&_35$$5, "<tr><th colspan=\"2\">Memory</th></tr><tr><td>Usage</td><td>", &_34$$5, "</td></tr>");
		zephir_concat_self(&html, &_35$$5 TSRMLS_CC);
		zephir_concat_self_str(&html, SL("</table></div>") TSRMLS_CC);
		if (Z_TYPE_P(&dataVars) == IS_ARRAY) {
			zephir_concat_self_str(&html, SL("<div id=\"error-tabs-6\"><table cellspacing=\"0\" align=\"center\" class=\"superglobal-detail\">") TSRMLS_CC);
			zephir_concat_self_str(&html, SL("<tr><th>Key</th><th>Value</th></tr>") TSRMLS_CC);
			zephir_is_iterable(&dataVars, 0, "phalcon/debug.zep", 713);
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&dataVars), _37$$13, _38$$13, _36$$13)
			{
				ZEPHIR_INIT_NVAR(&keyVar);
				if (_38$$13 != NULL) { 
					ZVAL_STR_COPY(&keyVar, _38$$13);
				} else {
					ZVAL_LONG(&keyVar, _37$$13);
				}
				ZEPHIR_INIT_NVAR(&dataVar);
				ZVAL_COPY(&dataVar, _36$$13);
				zephir_array_fetch_long(&_40$$14, &dataVar, 0, PH_NOISY | PH_READONLY, "phalcon/debug.zep", 711 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&_39$$14, this_ptr, "_getvardump", &_27, 0, &_40$$14);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_41$$14);
				ZEPHIR_CONCAT_SVSVS(&_41$$14, "<tr><td class=\"key\">", &keyVar, "</td><td>", &_39$$14, "</td></tr>");
				zephir_concat_self(&html, &_41$$14 TSRMLS_CC);
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&dataVar);
			ZEPHIR_INIT_NVAR(&keyVar);
			zephir_concat_self_str(&html, SL("</table></div>") TSRMLS_CC);
		}
		zephir_concat_self_str(&html, SL("</div>") TSRMLS_CC);
	}
	ZEPHIR_CALL_METHOD(&_42, this_ptr, "getjssources", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_43);
	ZEPHIR_CONCAT_VS(&_43, &_42, "</div></body></html>");
	zephir_concat_self(&html, &_43 TSRMLS_CC);
	zend_print_zval(&html, 0);
	zephir_update_static_property_ce(phalcon_debug_ce, SL("_isActive"), &__$false);
	RETURN_MM_BOOL(1);

}

