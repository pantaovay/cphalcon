
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/concat.h"


/**
 * Phalcon\Mvc\Router
 *
 * Phalcon\Mvc\Router is the standard framework router. Routing is the
 * process of taking a URI endpoint (that part of the URI which comes after the base URL) and
 * decomposing it into parameters to determine which module, controller, and
 * action of that controller should receive the request
 *
 * <code>
 * use Phalcon\Mvc\Router;
 *
 * $router = new Router();
 *
 * $router->add(
 *     "/documentation/{chapter}/{name}\.{type:[a-z]+}",
 *     [
 *         "controller" => "documentation",
 *         "action"     => "show",
 *     ]
 * );
 *
 * $router->handle();
 *
 * echo $router->getControllerName();
 * </code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Router) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Mvc, Router, phalcon, mvc_router, phalcon_mvc_router_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_router_ce, SL("_dependencyInjector"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_router_ce, SL("_eventsManager"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_router_ce, SL("_uriSource"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_router_ce, SL("_namespace"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_router_ce, SL("_module"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_router_ce, SL("_controller"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_router_ce, SL("_action"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_router_ce, SL("_params"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_router_ce, SL("_routes"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_router_ce, SL("_matchedRoute"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_router_ce, SL("_matches"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(phalcon_mvc_router_ce, SL("_wasMatched"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_router_ce, SL("_defaultNamespace"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_router_ce, SL("_defaultModule"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_router_ce, SL("_defaultController"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_router_ce, SL("_defaultAction"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_router_ce, SL("_defaultParams"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_router_ce, SL("_removeExtraSlashes"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_router_ce, SL("_notFoundPaths"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_router_ce, SL("_keyRouteNames"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_router_ce, SL("_keyRouteIds"), ZEND_ACC_PROTECTED TSRMLS_CC);

	phalcon_mvc_router_ce->create_object = zephir_init_properties_Phalcon_Mvc_Router;
	zephir_declare_class_constant_long(phalcon_mvc_router_ce, SL("URI_SOURCE_GET_URL"), 0);

	zephir_declare_class_constant_long(phalcon_mvc_router_ce, SL("URI_SOURCE_SERVER_REQUEST_URI"), 1);

	zephir_declare_class_constant_long(phalcon_mvc_router_ce, SL("POSITION_FIRST"), 0);

	zephir_declare_class_constant_long(phalcon_mvc_router_ce, SL("POSITION_LAST"), 1);

	zend_class_implements(phalcon_mvc_router_ce TSRMLS_CC, 1, phalcon_di_injectionawareinterface_ce);
	zend_class_implements(phalcon_mvc_router_ce TSRMLS_CC, 1, phalcon_mvc_routerinterface_ce);
	zend_class_implements(phalcon_mvc_router_ce TSRMLS_CC, 1, phalcon_events_eventsawareinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Phalcon_Mvc_Router, getKeyRouteNames) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_keyRouteNames");

}

PHP_METHOD(Phalcon_Mvc_Router, setKeyRouteNames) {

	zval *keyRouteNames, keyRouteNames_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&keyRouteNames_sub);

	zephir_fetch_params(0, 1, 0, &keyRouteNames);



	zephir_update_property_zval(this_ptr, SL("_keyRouteNames"), keyRouteNames);
	RETURN_THISW();

}

PHP_METHOD(Phalcon_Mvc_Router, getKeyRouteIds) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_keyRouteIds");

}

PHP_METHOD(Phalcon_Mvc_Router, setKeyRouteIds) {

	zval *keyRouteIds, keyRouteIds_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&keyRouteIds_sub);

	zephir_fetch_params(0, 1, 0, &keyRouteIds);



	zephir_update_property_zval(this_ptr, SL("_keyRouteIds"), keyRouteIds);
	RETURN_THISW();

}

/**
 * Phalcon\Mvc\Router constructor
 */
PHP_METHOD(Phalcon_Mvc_Router, __construct) {

	zval routes, _1$$3, _3$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *defaultRoutes_param = NULL, _0$$3, _2$$3, _4$$3;
	zend_bool defaultRoutes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&routes);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &defaultRoutes_param);

	if (!defaultRoutes_param) {
		defaultRoutes = 1;
	} else {
	if (UNEXPECTED(Z_TYPE_P(defaultRoutes_param) != IS_TRUE && Z_TYPE_P(defaultRoutes_param) != IS_FALSE)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'defaultRoutes' must be of the type bool") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	defaultRoutes = (Z_TYPE_P(defaultRoutes_param) == IS_TRUE);
	}


	ZEPHIR_INIT_VAR(&routes);
	array_init(&routes);
	if (defaultRoutes) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_mvc_router_route_ce);
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_create_array(&_1$$3, 1, 0 TSRMLS_CC);
		add_assoc_long_ex(&_1$$3, SL("controller"), 1);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "#^/([\\w0-9\\_\\-]+)[/]{0,1}$#u");
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 74, &_2$$3, &_1$$3);
		zephir_check_call_status();
		zephir_array_append(&routes, &_0$$3, PH_SEPARATE, "phalcon/mvc/router.zep", 124);
		ZEPHIR_INIT_NVAR(&_2$$3);
		object_init_ex(&_2$$3, phalcon_mvc_router_route_ce);
		ZEPHIR_INIT_VAR(&_3$$3);
		zephir_create_array(&_3$$3, 3, 0 TSRMLS_CC);
		add_assoc_long_ex(&_3$$3, SL("controller"), 1);
		add_assoc_long_ex(&_3$$3, SL("action"), 2);
		add_assoc_long_ex(&_3$$3, SL("params"), 3);
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "#^/([\\w0-9\\_\\-]+)/([\\w0-9\\.\\_]+)(/.*)*$#u");
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "__construct", NULL, 74, &_4$$3, &_3$$3);
		zephir_check_call_status();
		zephir_array_append(&routes, &_2$$3, PH_SEPARATE, "phalcon/mvc/router.zep", 130);
	}
	zephir_update_property_zval(this_ptr, SL("_routes"), &routes);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the dependency injector
 */
PHP_METHOD(Phalcon_Mvc_Router, setDI) {

	zval *dependencyInjector, dependencyInjector_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dependencyInjector_sub);

	zephir_fetch_params(0, 1, 0, &dependencyInjector);



	zephir_update_property_zval(this_ptr, SL("_dependencyInjector"), dependencyInjector);

}

/**
 * Returns the internal dependency injector
 */
PHP_METHOD(Phalcon_Mvc_Router, getDI) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_dependencyInjector");

}

/**
 * Sets the events manager
 */
PHP_METHOD(Phalcon_Mvc_Router, setEventsManager) {

	zval *eventsManager, eventsManager_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eventsManager_sub);

	zephir_fetch_params(0, 1, 0, &eventsManager);



	zephir_update_property_zval(this_ptr, SL("_eventsManager"), eventsManager);

}

/**
 * Returns the internal event manager
 */
PHP_METHOD(Phalcon_Mvc_Router, getEventsManager) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_eventsManager");

}

/**
 * Get rewrite info. This info is read from $_GET["_url"]. This returns '/' if the rewrite information cannot be read
 */
PHP_METHOD(Phalcon_Mvc_Router, getRewriteUri) {

	zval *_GET, *_SERVER, url, urlParts, realUri, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&urlParts);
	ZVAL_UNDEF(&realUri);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SL("_SERVER"));
	zephir_get_global(&_GET, SL("_GET"));

	zephir_read_property(&_0, this_ptr, SL("_uriSource"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_OBS_VAR(&url);
		if (zephir_array_isset_string_fetch(&url, _GET, SL("_url"), 0)) {
			if (!(ZEPHIR_IS_EMPTY(&url))) {
				RETURN_CCTOR(&url);
			}
		}
	} else {
		ZEPHIR_OBS_NVAR(&url);
		if (zephir_array_isset_string_fetch(&url, _SERVER, SL("REQUEST_URI"), 0)) {
			ZEPHIR_INIT_VAR(&urlParts);
			zephir_fast_explode_str(&urlParts, SL("?"), &url, LONG_MAX TSRMLS_CC);
			zephir_array_fetch_long(&realUri, &urlParts, 0, PH_NOISY | PH_READONLY, "phalcon/mvc/router.zep", 190 TSRMLS_CC);
			if (!(ZEPHIR_IS_EMPTY(&realUri))) {
				RETURN_CTOR(&realUri);
			}
		}
	}
	RETURN_MM_STRING("/");

}

/**
 * Sets the URI source. One of the URI_SOURCE_* constants
 *
 * <code>
 * $router->setUriSource(
 *     Router::URI_SOURCE_SERVER_REQUEST_URI
 * );
 * </code>
 */
PHP_METHOD(Phalcon_Mvc_Router, setUriSource) {

	zval *uriSource, uriSource_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uriSource_sub);

	zephir_fetch_params(0, 1, 0, &uriSource);



	zephir_update_property_zval(this_ptr, SL("_uriSource"), uriSource);
	RETURN_THISW();

}

/**
 * Set whether router must remove the extra slashes in the handled routes
 */
PHP_METHOD(Phalcon_Mvc_Router, removeExtraSlashes) {

	zval *remove_param = NULL, __$true, __$false;
	zend_bool remove;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);

	zephir_fetch_params(0, 1, 0, &remove_param);

	if (UNEXPECTED(Z_TYPE_P(remove_param) != IS_TRUE && Z_TYPE_P(remove_param) != IS_FALSE)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'remove' must be of the type bool") TSRMLS_CC);
		RETURN_NULL();
	}
	remove = (Z_TYPE_P(remove_param) == IS_TRUE);


	if (remove) {
		zephir_update_property_zval(this_ptr, SL("_removeExtraSlashes"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("_removeExtraSlashes"), &__$false);
	}
	RETURN_THISW();

}

/**
 * Sets the name of the default namespace
 */
PHP_METHOD(Phalcon_Mvc_Router, setDefaultNamespace) {

	zval *namespaceName_param = NULL;
	zval namespaceName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&namespaceName);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &namespaceName_param);

	if (UNEXPECTED(Z_TYPE_P(namespaceName_param) != IS_STRING && Z_TYPE_P(namespaceName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'namespaceName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(namespaceName_param) == IS_STRING)) {
		zephir_get_strval(&namespaceName, namespaceName_param);
	} else {
		ZEPHIR_INIT_VAR(&namespaceName);
		ZVAL_EMPTY_STRING(&namespaceName);
	}


	zephir_update_property_zval(this_ptr, SL("_defaultNamespace"), &namespaceName);
	RETURN_THIS();

}

/**
 * Sets the name of the default module
 */
PHP_METHOD(Phalcon_Mvc_Router, setDefaultModule) {

	zval *moduleName_param = NULL;
	zval moduleName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&moduleName);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &moduleName_param);

	if (UNEXPECTED(Z_TYPE_P(moduleName_param) != IS_STRING && Z_TYPE_P(moduleName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'moduleName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(moduleName_param) == IS_STRING)) {
		zephir_get_strval(&moduleName, moduleName_param);
	} else {
		ZEPHIR_INIT_VAR(&moduleName);
		ZVAL_EMPTY_STRING(&moduleName);
	}


	zephir_update_property_zval(this_ptr, SL("_defaultModule"), &moduleName);
	RETURN_THIS();

}

/**
 * Sets the default controller name
 */
PHP_METHOD(Phalcon_Mvc_Router, setDefaultController) {

	zval *controllerName_param = NULL;
	zval controllerName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&controllerName);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &controllerName_param);

	if (UNEXPECTED(Z_TYPE_P(controllerName_param) != IS_STRING && Z_TYPE_P(controllerName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'controllerName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(controllerName_param) == IS_STRING)) {
		zephir_get_strval(&controllerName, controllerName_param);
	} else {
		ZEPHIR_INIT_VAR(&controllerName);
		ZVAL_EMPTY_STRING(&controllerName);
	}


	zephir_update_property_zval(this_ptr, SL("_defaultController"), &controllerName);
	RETURN_THIS();

}

/**
 * Sets the default action name
 */
PHP_METHOD(Phalcon_Mvc_Router, setDefaultAction) {

	zval *actionName_param = NULL;
	zval actionName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&actionName);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &actionName_param);

	if (UNEXPECTED(Z_TYPE_P(actionName_param) != IS_STRING && Z_TYPE_P(actionName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'actionName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(actionName_param) == IS_STRING)) {
		zephir_get_strval(&actionName, actionName_param);
	} else {
		ZEPHIR_INIT_VAR(&actionName);
		ZVAL_EMPTY_STRING(&actionName);
	}


	zephir_update_property_zval(this_ptr, SL("_defaultAction"), &actionName);
	RETURN_THIS();

}

/**
 * Sets an array of default paths. If a route is missing a path the router will use the defined here
 * This method must not be used to set a 404 route
 *
 *<code>
 * $router->setDefaults(
 *     [
 *         "module" => "common",
 *         "action" => "index",
 *     ]
 * );
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Router, setDefaults) {

	zval *defaults_param = NULL, namespaceName, module, controller, action, params;
	zval defaults;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&defaults);
	ZVAL_UNDEF(&namespaceName);
	ZVAL_UNDEF(&module);
	ZVAL_UNDEF(&controller);
	ZVAL_UNDEF(&action);
	ZVAL_UNDEF(&params);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &defaults_param);

	ZEPHIR_OBS_COPY_OR_DUP(&defaults, defaults_param);


	if (zephir_array_isset_string_fetch(&namespaceName, &defaults, SL("namespace"), 1)) {
		zephir_update_property_zval(this_ptr, SL("_defaultNamespace"), &namespaceName);
	}
	if (zephir_array_isset_string_fetch(&module, &defaults, SL("module"), 1)) {
		zephir_update_property_zval(this_ptr, SL("_defaultModule"), &module);
	}
	if (zephir_array_isset_string_fetch(&controller, &defaults, SL("controller"), 1)) {
		zephir_update_property_zval(this_ptr, SL("_defaultController"), &controller);
	}
	if (zephir_array_isset_string_fetch(&action, &defaults, SL("action"), 1)) {
		zephir_update_property_zval(this_ptr, SL("_defaultAction"), &action);
	}
	if (zephir_array_isset_string_fetch(&params, &defaults, SL("params"), 1)) {
		zephir_update_property_zval(this_ptr, SL("_defaultParams"), &params);
	}
	RETURN_THIS();

}

/**
 * Returns an array of default parameters
 */
PHP_METHOD(Phalcon_Mvc_Router, getDefaults) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_create_array(return_value, 5, 0 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("_defaultNamespace"), PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("namespace"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("_defaultModule"), PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("module"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("_defaultController"), PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("controller"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("_defaultAction"), PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("action"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("_defaultParams"), PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("params"), &_0, PH_COPY | PH_SEPARATE);
	RETURN_MM();

}

/**
 * Handles routing information received from the rewrite engine
 *
 *<code>
 * // Read the info from the rewrite engine
 * $router->handle();
 *
 * // Manually passing an URL
 * $router->handle("/posts/edit/1");
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Router, handle) {

	zend_string *_24$$34;
	zend_ulong _23$$34;
	zval _19$$29, _30$$40, _32$$43;
	zend_bool _1, _28$$35;
	zephir_fcall_cache_entry *_16 = NULL, *_18 = NULL, *_21 = NULL, *_27 = NULL, *_33 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *uri_param = NULL, __$true, __$false, __$null, realUri, request, currentHostName, routeFound, parts, params, matches, notFoundPaths, vnamespace, module, controller, action, paramsStr, strParams, route, methods, dependencyInjector, hostname, regexHostName, matched, pattern, handledUri, beforeMatch, paths, converters, part, position, matchPosition, converter, eventsManager, _0, _4, *_5, _34, _35, _36, _37, _38, _2$$5, _3$$7, _6$$10, _7$$10, _8$$10, _9$$9, _10$$9, _11$$14, _12$$14, _13$$14, _14$$18, _15$$24, _17$$28, _20$$32, *_22$$34, _25$$36, _26$$36, _29$$40, _31$$43, _39$$60, _40$$62, _41$$64;
	zval uri;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&realUri);
	ZVAL_UNDEF(&request);
	ZVAL_UNDEF(&currentHostName);
	ZVAL_UNDEF(&routeFound);
	ZVAL_UNDEF(&parts);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&matches);
	ZVAL_UNDEF(&notFoundPaths);
	ZVAL_UNDEF(&vnamespace);
	ZVAL_UNDEF(&module);
	ZVAL_UNDEF(&controller);
	ZVAL_UNDEF(&action);
	ZVAL_UNDEF(&paramsStr);
	ZVAL_UNDEF(&strParams);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&methods);
	ZVAL_UNDEF(&dependencyInjector);
	ZVAL_UNDEF(&hostname);
	ZVAL_UNDEF(&regexHostName);
	ZVAL_UNDEF(&matched);
	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&handledUri);
	ZVAL_UNDEF(&beforeMatch);
	ZVAL_UNDEF(&paths);
	ZVAL_UNDEF(&converters);
	ZVAL_UNDEF(&part);
	ZVAL_UNDEF(&position);
	ZVAL_UNDEF(&matchPosition);
	ZVAL_UNDEF(&converter);
	ZVAL_UNDEF(&eventsManager);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_34);
	ZVAL_UNDEF(&_35);
	ZVAL_UNDEF(&_36);
	ZVAL_UNDEF(&_37);
	ZVAL_UNDEF(&_38);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$7);
	ZVAL_UNDEF(&_6$$10);
	ZVAL_UNDEF(&_7$$10);
	ZVAL_UNDEF(&_8$$10);
	ZVAL_UNDEF(&_9$$9);
	ZVAL_UNDEF(&_10$$9);
	ZVAL_UNDEF(&_11$$14);
	ZVAL_UNDEF(&_12$$14);
	ZVAL_UNDEF(&_13$$14);
	ZVAL_UNDEF(&_14$$18);
	ZVAL_UNDEF(&_15$$24);
	ZVAL_UNDEF(&_17$$28);
	ZVAL_UNDEF(&_20$$32);
	ZVAL_UNDEF(&_25$$36);
	ZVAL_UNDEF(&_26$$36);
	ZVAL_UNDEF(&_29$$40);
	ZVAL_UNDEF(&_31$$43);
	ZVAL_UNDEF(&_39$$60);
	ZVAL_UNDEF(&_40$$62);
	ZVAL_UNDEF(&_41$$64);
	ZVAL_UNDEF(&_19$$29);
	ZVAL_UNDEF(&_30$$40);
	ZVAL_UNDEF(&_32$$43);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &uri_param);

	if (!uri_param) {
		ZEPHIR_INIT_VAR(&uri);
		ZVAL_STRING(&uri, "");
	} else {
		zephir_get_strval(&uri, uri_param);
	}


	if (!(!(Z_TYPE_P(&uri) == IS_UNDEF) && Z_STRLEN_P(&uri))) {
		ZEPHIR_CALL_METHOD(&realUri, this_ptr, "getrewriteuri", NULL, 0);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(&realUri, &uri);
	}
	zephir_read_property(&_0, this_ptr, SL("_removeExtraSlashes"), PH_NOISY_CC | PH_READONLY);
	_1 = zephir_is_true(&_0);
	if (_1) {
		_1 = !ZEPHIR_IS_STRING(&realUri, "/");
	}
	if (_1) {
		ZEPHIR_INIT_VAR(&_2$$5);
		ZVAL_STRING(&_2$$5, "/");
		ZEPHIR_INIT_VAR(&handledUri);
		zephir_fast_trim(&handledUri, &realUri, &_2$$5, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
	} else {
		ZEPHIR_CPY_WRT(&handledUri, &realUri);
	}
	ZEPHIR_INIT_VAR(&request);
	ZVAL_NULL(&request);
	ZEPHIR_INIT_VAR(&currentHostName);
	ZVAL_NULL(&currentHostName);
	ZEPHIR_INIT_VAR(&routeFound);
	ZVAL_BOOL(&routeFound, 0);
	ZEPHIR_INIT_VAR(&parts);
	array_init(&parts);
	ZEPHIR_INIT_VAR(&params);
	array_init(&params);
	ZEPHIR_INIT_VAR(&matches);
	ZVAL_NULL(&matches);
	if (0) {
		zephir_update_property_zval(this_ptr, SL("_wasMatched"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("_wasMatched"), &__$false);
	}
	zephir_update_property_zval(this_ptr, SL("_matchedRoute"), &__$null);
	ZEPHIR_OBS_VAR(&eventsManager);
	zephir_read_property(&eventsManager, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_3$$7);
		ZVAL_STRING(&_3$$7, "router:beforeCheckRoutes");
		ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_3$$7, this_ptr);
		zephir_check_call_status();
	}
	zephir_read_property(&_4, this_ptr, SL("_routes"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_4, 0, "phalcon/mvc/router.zep", 586);
	ZEND_HASH_REVERSE_FOREACH_VAL(Z_ARRVAL_P(&_4), _5)
	{
		ZEPHIR_INIT_NVAR(&route);
		ZVAL_COPY(&route, _5);
		ZEPHIR_INIT_NVAR(&params);
		array_init(&params);
		ZEPHIR_INIT_NVAR(&matches);
		ZVAL_NULL(&matches);
		ZEPHIR_CALL_METHOD(&methods, &route, "gethttpmethods", NULL, 0);
		zephir_check_call_status();
		if (Z_TYPE_P(&methods) != IS_NULL) {
			if (Z_TYPE_P(&request) == IS_NULL) {
				zephir_read_property(&_6$$10, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CPY_WRT(&dependencyInjector, &_6$$10);
				if (Z_TYPE_P(&dependencyInjector) != IS_OBJECT) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exception_ce, "A dependency injection container is required to access the 'request' service", "phalcon/mvc/router.zep", 391);
					return;
				}
				ZEPHIR_INIT_NVAR(&_8$$10);
				ZVAL_STRING(&_8$$10, "request");
				ZEPHIR_CALL_METHOD(&_7$$10, &dependencyInjector, "getshared", NULL, 0, &_8$$10);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&request, &_7$$10);
			}
			ZVAL_BOOL(&_10$$9, 1);
			ZEPHIR_CALL_METHOD(&_9$$9, &request, "ismethod", NULL, 0, &methods, &_10$$9);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_9$$9)) {
				continue;
			}
		}
		ZEPHIR_CALL_METHOD(&hostname, &route, "gethostname", NULL, 0);
		zephir_check_call_status();
		if (Z_TYPE_P(&hostname) != IS_NULL) {
			if (Z_TYPE_P(&request) == IS_NULL) {
				zephir_read_property(&_11$$14, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CPY_WRT(&dependencyInjector, &_11$$14);
				if (Z_TYPE_P(&dependencyInjector) != IS_OBJECT) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exception_ce, "A dependency injection container is required to access the 'request' service", "phalcon/mvc/router.zep", 418);
					return;
				}
				ZEPHIR_INIT_NVAR(&_13$$14);
				ZVAL_STRING(&_13$$14, "request");
				ZEPHIR_CALL_METHOD(&_12$$14, &dependencyInjector, "getshared", NULL, 0, &_13$$14);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&request, &_12$$14);
			}
			if (Z_TYPE_P(&currentHostName) == IS_NULL) {
				ZEPHIR_CALL_METHOD(&currentHostName, &request, "gethttphost", NULL, 0);
				zephir_check_call_status();
			}
			if (!(zephir_is_true(&currentHostName))) {
				continue;
			}
			if (zephir_memnstr_str(&hostname, SL("("), "phalcon/mvc/router.zep", 441)) {
				if (!(zephir_memnstr_str(&hostname, SL("#"), "phalcon/mvc/router.zep", 442))) {
					ZEPHIR_INIT_NVAR(&regexHostName);
					ZEPHIR_CONCAT_SV(&regexHostName, "#^", &hostname);
					if (!(zephir_memnstr_str(&hostname, SL(":"), "phalcon/mvc/router.zep", 444))) {
						zephir_concat_self_str(&regexHostName, SL("(:[[:digit:]]+)?") TSRMLS_CC);
					}
					zephir_concat_self_str(&regexHostName, SL("$#i") TSRMLS_CC);
				} else {
					ZEPHIR_CPY_WRT(&regexHostName, &hostname);
				}
				ZEPHIR_INIT_NVAR(&_14$$18);
				ZEPHIR_INIT_NVAR(&matched);
				zephir_preg_match(&matched, &regexHostName, &currentHostName, &_14$$18, 0, 0 , 0  TSRMLS_CC);
			} else {
				ZEPHIR_INIT_NVAR(&matched);
				ZVAL_BOOL(&matched, ZEPHIR_IS_EQUAL(&currentHostName, &hostname));
			}
			if (!(zephir_is_true(&matched))) {
				continue;
			}
		}
		if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
			ZEPHIR_INIT_NVAR(&_15$$24);
			ZVAL_STRING(&_15$$24, "router:beforeCheckRoute");
			ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", &_16, 0, &_15$$24, this_ptr, &route);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(&pattern, &route, "getcompiledpattern", NULL, 0);
		zephir_check_call_status();
		if (zephir_memnstr_str(&pattern, SL("^"), "phalcon/mvc/router.zep", 470)) {
			ZEPHIR_INIT_NVAR(&routeFound);
			zephir_preg_match(&routeFound, &pattern, &handledUri, &matches, 0, 0 , 0  TSRMLS_CC);
		} else {
			ZEPHIR_INIT_NVAR(&routeFound);
			ZVAL_BOOL(&routeFound, ZEPHIR_IS_EQUAL(&pattern, &handledUri));
		}
		if (zephir_is_true(&routeFound)) {
			if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
				ZEPHIR_INIT_NVAR(&_17$$28);
				ZVAL_STRING(&_17$$28, "router:matchedRoute");
				ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", &_18, 0, &_17$$28, this_ptr, &route);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&beforeMatch, &route, "getbeforematch", NULL, 0);
			zephir_check_call_status();
			if (Z_TYPE_P(&beforeMatch) != IS_NULL) {
				if (!(zephir_is_callable(&beforeMatch TSRMLS_CC))) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exception_ce, "Before-Match callback is not callable in matched route", "phalcon/mvc/router.zep", 492);
					return;
				}
				ZEPHIR_INIT_NVAR(&_19$$29);
				zephir_create_array(&_19$$29, 3, 0 TSRMLS_CC);
				zephir_array_fast_append(&_19$$29, &handledUri);
				zephir_array_fast_append(&_19$$29, &route);
				zephir_array_fast_append(&_19$$29, this_ptr);
				ZEPHIR_INIT_NVAR(&routeFound);
				ZEPHIR_CALL_USER_FUNC_ARRAY(&routeFound, &beforeMatch, &_19$$29);
				zephir_check_call_status();
			}
		} else {
			if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
				ZEPHIR_INIT_NVAR(&_20$$32);
				ZVAL_STRING(&_20$$32, "router:notMatchedRoute");
				ZEPHIR_CALL_METHOD(&routeFound, &eventsManager, "fire", &_21, 0, &_20$$32, this_ptr, &route);
				zephir_check_call_status();
			}
		}
		if (zephir_is_true(&routeFound)) {
			ZEPHIR_CALL_METHOD(&paths, &route, "getpaths", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&parts, &paths);
			if (Z_TYPE_P(&matches) == IS_ARRAY) {
				ZEPHIR_CALL_METHOD(&converters, &route, "getconverters", NULL, 0);
				zephir_check_call_status();
				zephir_is_iterable(&paths, 0, "phalcon/mvc/router.zep", 575);
				ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&paths), _23$$34, _24$$34, _22$$34)
				{
					ZEPHIR_INIT_NVAR(&part);
					if (_24$$34 != NULL) { 
						ZVAL_STR_COPY(&part, _24$$34);
					} else {
						ZVAL_LONG(&part, _23$$34);
					}
					ZEPHIR_INIT_NVAR(&position);
					ZVAL_COPY(&position, _22$$34);
					if (Z_TYPE_P(&part) != IS_STRING) {
						ZEPHIR_INIT_NVAR(&_25$$36);
						object_init_ex(&_25$$36, phalcon_mvc_router_exception_ce);
						ZEPHIR_INIT_LNVAR(_26$$36);
						ZEPHIR_CONCAT_SV(&_26$$36, "Wrong key in paths: ", &part);
						ZEPHIR_CALL_METHOD(NULL, &_25$$36, "__construct", &_27, 4, &_26$$36);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_25$$36, "phalcon/mvc/router.zep", 528 TSRMLS_CC);
						ZEPHIR_MM_RESTORE();
						return;
					}
					_28$$35 = Z_TYPE_P(&position) != IS_STRING;
					if (_28$$35) {
						_28$$35 = Z_TYPE_P(&position) != IS_LONG;
					}
					if (_28$$35) {
						continue;
					}
					ZEPHIR_OBS_NVAR(&matchPosition);
					if (zephir_array_isset_fetch(&matchPosition, &matches, &position, 0 TSRMLS_CC)) {
						if (Z_TYPE_P(&converters) == IS_ARRAY) {
							ZEPHIR_OBS_NVAR(&converter);
							if (zephir_array_isset_fetch(&converter, &converters, &part, 0 TSRMLS_CC)) {
								ZEPHIR_INIT_NVAR(&_29$$40);
								ZEPHIR_INIT_NVAR(&_30$$40);
								zephir_create_array(&_30$$40, 1, 0 TSRMLS_CC);
								zephir_array_fast_append(&_30$$40, &matchPosition);
								ZEPHIR_CALL_USER_FUNC_ARRAY(&_29$$40, &converter, &_30$$40);
								zephir_check_call_status();
								zephir_array_update_zval(&parts, &part, &_29$$40, PH_COPY | PH_SEPARATE);
								continue;
							}
						}
						zephir_array_update_zval(&parts, &part, &matchPosition, PH_COPY | PH_SEPARATE);
					} else {
						if (Z_TYPE_P(&converters) == IS_ARRAY) {
							ZEPHIR_OBS_NVAR(&converter);
							if (zephir_array_isset_fetch(&converter, &converters, &part, 0 TSRMLS_CC)) {
								ZEPHIR_INIT_NVAR(&_31$$43);
								ZEPHIR_INIT_NVAR(&_32$$43);
								zephir_create_array(&_32$$43, 1, 0 TSRMLS_CC);
								zephir_array_fast_append(&_32$$43, &position);
								ZEPHIR_CALL_USER_FUNC_ARRAY(&_31$$43, &converter, &_32$$43);
								zephir_check_call_status();
								zephir_array_update_zval(&parts, &part, &_31$$43, PH_COPY | PH_SEPARATE);
							}
						} else {
							if (Z_TYPE_P(&position) == IS_LONG) {
								zephir_array_unset(&parts, &part, PH_SEPARATE);
							}
						}
					}
				} ZEND_HASH_FOREACH_END();
				ZEPHIR_INIT_NVAR(&position);
				ZEPHIR_INIT_NVAR(&part);
				zephir_update_property_zval(this_ptr, SL("_matches"), &matches);
			}
			zephir_update_property_zval(this_ptr, SL("_matchedRoute"), &route);
			break;
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&route);
	if (zephir_is_true(&routeFound)) {
		if (1) {
			zephir_update_property_zval(this_ptr, SL("_wasMatched"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, SL("_wasMatched"), &__$false);
		}
	} else {
		if (0) {
			zephir_update_property_zval(this_ptr, SL("_wasMatched"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, SL("_wasMatched"), &__$false);
		}
	}
	if (!(zephir_is_true(&routeFound))) {
		ZEPHIR_OBS_VAR(&notFoundPaths);
		zephir_read_property(&notFoundPaths, this_ptr, SL("_notFoundPaths"), PH_NOISY_CC);
		if (Z_TYPE_P(&notFoundPaths) != IS_NULL) {
			ZEPHIR_CALL_CE_STATIC(&parts, phalcon_mvc_router_route_ce, "getroutepaths", &_33, 0, &notFoundPaths);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&routeFound);
			ZVAL_BOOL(&routeFound, 1);
		}
	}
	zephir_read_property(&_34, this_ptr, SL("_defaultNamespace"), PH_NOISY_CC | PH_READONLY);
	zephir_update_property_zval(this_ptr, SL("_namespace"), &_34);
	zephir_read_property(&_35, this_ptr, SL("_defaultModule"), PH_NOISY_CC | PH_READONLY);
	zephir_update_property_zval(this_ptr, SL("_module"), &_35);
	zephir_read_property(&_36, this_ptr, SL("_defaultController"), PH_NOISY_CC | PH_READONLY);
	zephir_update_property_zval(this_ptr, SL("_controller"), &_36);
	zephir_read_property(&_37, this_ptr, SL("_defaultAction"), PH_NOISY_CC | PH_READONLY);
	zephir_update_property_zval(this_ptr, SL("_action"), &_37);
	zephir_read_property(&_38, this_ptr, SL("_defaultParams"), PH_NOISY_CC | PH_READONLY);
	zephir_update_property_zval(this_ptr, SL("_params"), &_38);
	if (zephir_is_true(&routeFound)) {
		ZEPHIR_OBS_VAR(&vnamespace);
		if (zephir_array_isset_string_fetch(&vnamespace, &parts, SL("namespace"), 0)) {
			if (!(zephir_is_numeric(&vnamespace))) {
				zephir_update_property_zval(this_ptr, SL("_namespace"), &vnamespace);
			}
			zephir_array_unset_string(&parts, SL("namespace"), PH_SEPARATE);
		}
		ZEPHIR_OBS_VAR(&module);
		if (zephir_array_isset_string_fetch(&module, &parts, SL("module"), 0)) {
			if (!(zephir_is_numeric(&module))) {
				zephir_update_property_zval(this_ptr, SL("_module"), &module);
			}
			zephir_array_unset_string(&parts, SL("module"), PH_SEPARATE);
		}
		ZEPHIR_OBS_VAR(&controller);
		if (zephir_array_isset_string_fetch(&controller, &parts, SL("controller"), 0)) {
			if (!(zephir_is_numeric(&controller))) {
				zephir_update_property_zval(this_ptr, SL("_controller"), &controller);
			}
			zephir_array_unset_string(&parts, SL("controller"), PH_SEPARATE);
		}
		ZEPHIR_OBS_VAR(&action);
		if (zephir_array_isset_string_fetch(&action, &parts, SL("action"), 0)) {
			if (!(zephir_is_numeric(&action))) {
				zephir_update_property_zval(this_ptr, SL("_action"), &action);
			}
			zephir_array_unset_string(&parts, SL("action"), PH_SEPARATE);
		}
		ZEPHIR_OBS_VAR(&paramsStr);
		if (zephir_array_isset_string_fetch(&paramsStr, &parts, SL("params"), 0)) {
			if (Z_TYPE_P(&paramsStr) == IS_STRING) {
				ZEPHIR_INIT_VAR(&_39$$60);
				ZVAL_STRING(&_39$$60, "/");
				ZEPHIR_INIT_VAR(&strParams);
				zephir_fast_trim(&strParams, &paramsStr, &_39$$60, ZEPHIR_TRIM_BOTH TSRMLS_CC);
				if (!ZEPHIR_IS_STRING_IDENTICAL(&strParams, "")) {
					ZEPHIR_INIT_NVAR(&params);
					zephir_fast_explode_str(&params, SL("/"), &strParams, LONG_MAX TSRMLS_CC);
				}
			}
			zephir_array_unset_string(&parts, SL("params"), PH_SEPARATE);
		}
		if (zephir_fast_count_int(&params TSRMLS_CC)) {
			ZEPHIR_INIT_VAR(&_40$$62);
			zephir_fast_array_merge(&_40$$62, &params, &parts TSRMLS_CC);
			zephir_update_property_zval(this_ptr, SL("_params"), &_40$$62);
		} else {
			zephir_update_property_zval(this_ptr, SL("_params"), &parts);
		}
	}
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_41$$64);
		ZVAL_STRING(&_41$$64, "router:afterCheckRoutes");
		ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_41$$64, this_ptr);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Attach Route object to the routes stack.
 *
 * <code>
 * use Phalcon\Mvc\Router;
 * use Phalcon\Mvc\Router\Route;
 *
 * class CustomRoute extends Route {
 *      // ...
 * }
 *
 * $router = new Router();
 *
 * $router->attach(
 *     new CustomRoute("/about", "About::index", ["GET", "HEAD"]),
 *     Router::POSITION_FIRST
 * );
 * </code>
 *
 * @todo Add to the interface for 4.0.0
 */
PHP_METHOD(Phalcon_Mvc_Router, attach) {

	zval _1$$4;
	zval *route, route_sub, *position = NULL, position_sub, _0$$4, _2$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&route_sub);
	ZVAL_UNDEF(&position_sub);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_1$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &route, &position);

	if (!position) {
		position = &position_sub;
		ZEPHIR_INIT_VAR(position);
		ZVAL_LONG(position, 1);
	}


	do {
		if (ZEPHIR_IS_LONG(position, 1)) {
			zephir_update_property_array_append(this_ptr, SL("_routes"), route TSRMLS_CC);
			break;
		}
		if (ZEPHIR_IS_LONG(position, 0)) {
			ZEPHIR_INIT_VAR(&_0$$4);
			ZEPHIR_INIT_VAR(&_1$$4);
			zephir_create_array(&_1$$4, 1, 0 TSRMLS_CC);
			zephir_array_fast_append(&_1$$4, route);
			zephir_read_property(&_2$$4, this_ptr, SL("_routes"), PH_NOISY_CC | PH_READONLY);
			zephir_fast_array_merge(&_0$$4, &_1$$4, &_2$$4 TSRMLS_CC);
			zephir_update_property_zval(this_ptr, SL("_routes"), &_0$$4);
			break;
		}
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exception_ce, "Invalid route position", "phalcon/mvc/router.zep", 711);
		return;
	} while(0);

	RETURN_THIS();

}

/**
 * Adds a route to the router without any HTTP constraint
 *
 *<code>
 * use Phalcon\Mvc\Router;
 *
 * $router->add("/about", "About::index");
 * $router->add("/about", "About::index", ["GET", "POST"]);
 * $router->add("/about", "About::index", ["GET", "POST"], Router::POSITION_FIRST);
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Router, add) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, paths_sub, *httpMethods = NULL, httpMethods_sub, *position = NULL, position_sub, __$null, route;
	zval pattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&paths_sub);
	ZVAL_UNDEF(&httpMethods_sub);
	ZVAL_UNDEF(&position_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&route);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &pattern_param, &paths, &httpMethods, &position);

	if (UNEXPECTED(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(&pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(&pattern);
		ZVAL_EMPTY_STRING(&pattern);
	}
	if (!paths) {
		paths = &paths_sub;
		paths = &__$null;
	}
	if (!httpMethods) {
		httpMethods = &httpMethods_sub;
		httpMethods = &__$null;
	}
	if (!position) {
		position = &position_sub;
		ZEPHIR_INIT_VAR(position);
		ZVAL_LONG(position, 1);
	}


	ZEPHIR_INIT_VAR(&route);
	object_init_ex(&route, phalcon_mvc_router_route_ce);
	ZEPHIR_CALL_METHOD(NULL, &route, "__construct", NULL, 74, &pattern, paths, httpMethods);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "attach", NULL, 0, &route, position);
	zephir_check_call_status();
	RETURN_CCTOR(&route);

}

/**
 * Adds a route to the router that only match if the HTTP method is GET
 */
PHP_METHOD(Phalcon_Mvc_Router, addGet) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, paths_sub, *position = NULL, position_sub, __$null, _0;
	zval pattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&paths_sub);
	ZVAL_UNDEF(&position_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &pattern_param, &paths, &position);

	if (UNEXPECTED(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(&pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(&pattern);
		ZVAL_EMPTY_STRING(&pattern);
	}
	if (!paths) {
		paths = &paths_sub;
		paths = &__$null;
	}
	if (!position) {
		position = &position_sub;
		ZEPHIR_INIT_VAR(position);
		ZVAL_LONG(position, 1);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "GET");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "add", NULL, 0, &pattern, paths, &_0, position);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Adds a route to the router that only match if the HTTP method is POST
 */
PHP_METHOD(Phalcon_Mvc_Router, addPost) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, paths_sub, *position = NULL, position_sub, __$null, _0;
	zval pattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&paths_sub);
	ZVAL_UNDEF(&position_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &pattern_param, &paths, &position);

	if (UNEXPECTED(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(&pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(&pattern);
		ZVAL_EMPTY_STRING(&pattern);
	}
	if (!paths) {
		paths = &paths_sub;
		paths = &__$null;
	}
	if (!position) {
		position = &position_sub;
		ZEPHIR_INIT_VAR(position);
		ZVAL_LONG(position, 1);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "POST");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "add", NULL, 0, &pattern, paths, &_0, position);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Adds a route to the router that only match if the HTTP method is PUT
 */
PHP_METHOD(Phalcon_Mvc_Router, addPut) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, paths_sub, *position = NULL, position_sub, __$null, _0;
	zval pattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&paths_sub);
	ZVAL_UNDEF(&position_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &pattern_param, &paths, &position);

	if (UNEXPECTED(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(&pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(&pattern);
		ZVAL_EMPTY_STRING(&pattern);
	}
	if (!paths) {
		paths = &paths_sub;
		paths = &__$null;
	}
	if (!position) {
		position = &position_sub;
		ZEPHIR_INIT_VAR(position);
		ZVAL_LONG(position, 1);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "PUT");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "add", NULL, 0, &pattern, paths, &_0, position);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Adds a route to the router that only match if the HTTP method is PATCH
 */
PHP_METHOD(Phalcon_Mvc_Router, addPatch) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, paths_sub, *position = NULL, position_sub, __$null, _0;
	zval pattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&paths_sub);
	ZVAL_UNDEF(&position_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &pattern_param, &paths, &position);

	if (UNEXPECTED(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(&pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(&pattern);
		ZVAL_EMPTY_STRING(&pattern);
	}
	if (!paths) {
		paths = &paths_sub;
		paths = &__$null;
	}
	if (!position) {
		position = &position_sub;
		ZEPHIR_INIT_VAR(position);
		ZVAL_LONG(position, 1);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "PATCH");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "add", NULL, 0, &pattern, paths, &_0, position);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Adds a route to the router that only match if the HTTP method is DELETE
 */
PHP_METHOD(Phalcon_Mvc_Router, addDelete) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, paths_sub, *position = NULL, position_sub, __$null, _0;
	zval pattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&paths_sub);
	ZVAL_UNDEF(&position_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &pattern_param, &paths, &position);

	if (UNEXPECTED(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(&pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(&pattern);
		ZVAL_EMPTY_STRING(&pattern);
	}
	if (!paths) {
		paths = &paths_sub;
		paths = &__$null;
	}
	if (!position) {
		position = &position_sub;
		ZEPHIR_INIT_VAR(position);
		ZVAL_LONG(position, 1);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "DELETE");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "add", NULL, 0, &pattern, paths, &_0, position);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Add a route to the router that only match if the HTTP method is OPTIONS
 */
PHP_METHOD(Phalcon_Mvc_Router, addOptions) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, paths_sub, *position = NULL, position_sub, __$null, _0;
	zval pattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&paths_sub);
	ZVAL_UNDEF(&position_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &pattern_param, &paths, &position);

	if (UNEXPECTED(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(&pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(&pattern);
		ZVAL_EMPTY_STRING(&pattern);
	}
	if (!paths) {
		paths = &paths_sub;
		paths = &__$null;
	}
	if (!position) {
		position = &position_sub;
		ZEPHIR_INIT_VAR(position);
		ZVAL_LONG(position, 1);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "OPTIONS");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "add", NULL, 0, &pattern, paths, &_0, position);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Adds a route to the router that only match if the HTTP method is HEAD
 */
PHP_METHOD(Phalcon_Mvc_Router, addHead) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, paths_sub, *position = NULL, position_sub, __$null, _0;
	zval pattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&paths_sub);
	ZVAL_UNDEF(&position_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &pattern_param, &paths, &position);

	if (UNEXPECTED(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(&pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(&pattern);
		ZVAL_EMPTY_STRING(&pattern);
	}
	if (!paths) {
		paths = &paths_sub;
		paths = &__$null;
	}
	if (!position) {
		position = &position_sub;
		ZEPHIR_INIT_VAR(position);
		ZVAL_LONG(position, 1);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "HEAD");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "add", NULL, 0, &pattern, paths, &_0, position);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Adds a route to the router that only match if the HTTP method is PURGE (Squid and Varnish support)
 */
PHP_METHOD(Phalcon_Mvc_Router, addPurge) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, paths_sub, *position = NULL, position_sub, __$null, _0;
	zval pattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&paths_sub);
	ZVAL_UNDEF(&position_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &pattern_param, &paths, &position);

	if (UNEXPECTED(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(&pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(&pattern);
		ZVAL_EMPTY_STRING(&pattern);
	}
	if (!paths) {
		paths = &paths_sub;
		paths = &__$null;
	}
	if (!position) {
		position = &position_sub;
		ZEPHIR_INIT_VAR(position);
		ZVAL_LONG(position, 1);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "PURGE");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "add", NULL, 0, &pattern, paths, &_0, position);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Adds a route to the router that only match if the HTTP method is TRACE
 */
PHP_METHOD(Phalcon_Mvc_Router, addTrace) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, paths_sub, *position = NULL, position_sub, __$null, _0;
	zval pattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&paths_sub);
	ZVAL_UNDEF(&position_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &pattern_param, &paths, &position);

	if (UNEXPECTED(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(&pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(&pattern);
		ZVAL_EMPTY_STRING(&pattern);
	}
	if (!paths) {
		paths = &paths_sub;
		paths = &__$null;
	}
	if (!position) {
		position = &position_sub;
		ZEPHIR_INIT_VAR(position);
		ZVAL_LONG(position, 1);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "TRACE");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "add", NULL, 0, &pattern, paths, &_0, position);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Adds a route to the router that only match if the HTTP method is CONNECT
 */
PHP_METHOD(Phalcon_Mvc_Router, addConnect) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, paths_sub, *position = NULL, position_sub, __$null, _0;
	zval pattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&paths_sub);
	ZVAL_UNDEF(&position_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &pattern_param, &paths, &position);

	if (UNEXPECTED(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(&pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(&pattern);
		ZVAL_EMPTY_STRING(&pattern);
	}
	if (!paths) {
		paths = &paths_sub;
		paths = &__$null;
	}
	if (!position) {
		position = &position_sub;
		ZEPHIR_INIT_VAR(position);
		ZVAL_LONG(position, 1);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "CONNECT");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "add", NULL, 0, &pattern, paths, &_0, position);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Mounts a group of routes in the router
 */
PHP_METHOD(Phalcon_Mvc_Router, mount) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *group, group_sub, groupRoutes, beforeMatch, hostname, routes, route, eventsManager, _0$$3, *_1$$5, *_2$$7, _3$$9;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&group_sub);
	ZVAL_UNDEF(&groupRoutes);
	ZVAL_UNDEF(&beforeMatch);
	ZVAL_UNDEF(&hostname);
	ZVAL_UNDEF(&routes);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&eventsManager);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_3$$9);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &group);



	ZEPHIR_OBS_VAR(&eventsManager);
	zephir_read_property(&eventsManager, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZVAL_STRING(&_0$$3, "router:beforeMount");
		ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_0$$3, this_ptr, group);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&groupRoutes, group, "getroutes", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_fast_count_int(&groupRoutes TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exception_ce, "The group of routes does not contain any routes", "phalcon/mvc/router.zep", 837);
		return;
	}
	ZEPHIR_CALL_METHOD(&beforeMatch, group, "getbeforematch", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&beforeMatch) != IS_NULL) {
		zephir_is_iterable(&groupRoutes, 0, "phalcon/mvc/router.zep", 849);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&groupRoutes), _1$$5)
		{
			ZEPHIR_INIT_NVAR(&route);
			ZVAL_COPY(&route, _1$$5);
			ZEPHIR_CALL_METHOD(NULL, &route, "beforematch", NULL, 0, &beforeMatch);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&route);
	}
	ZEPHIR_CALL_METHOD(&hostname, group, "gethostname", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&hostname) != IS_NULL) {
		zephir_is_iterable(&groupRoutes, 0, "phalcon/mvc/router.zep", 858);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&groupRoutes), _2$$7)
		{
			ZEPHIR_INIT_NVAR(&route);
			ZVAL_COPY(&route, _2$$7);
			ZEPHIR_CALL_METHOD(NULL, &route, "sethostname", NULL, 0, &hostname);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&route);
	}
	ZEPHIR_OBS_VAR(&routes);
	zephir_read_property(&routes, this_ptr, SL("_routes"), PH_NOISY_CC);
	if (Z_TYPE_P(&routes) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_3$$9);
		zephir_fast_array_merge(&_3$$9, &routes, &groupRoutes TSRMLS_CC);
		zephir_update_property_zval(this_ptr, SL("_routes"), &_3$$9);
	} else {
		zephir_update_property_zval(this_ptr, SL("_routes"), &groupRoutes);
	}
	RETURN_THIS();

}

/**
 * Set a group of paths to be returned when none of the defined routes are matched
 */
PHP_METHOD(Phalcon_Mvc_Router, notFound) {

	zend_bool _0;
	zval *paths, paths_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&paths_sub);

	zephir_fetch_params(0, 1, 0, &paths);



	_0 = Z_TYPE_P(paths) != IS_ARRAY;
	if (_0) {
		_0 = Z_TYPE_P(paths) != IS_STRING;
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalcon_mvc_router_exception_ce, "The not-found paths must be an array or string", "phalcon/mvc/router.zep", 877);
		return;
	}
	zephir_update_property_zval(this_ptr, SL("_notFoundPaths"), paths);
	RETURN_THISW();

}

/**
 * Removes all the pre-defined routes
 */
PHP_METHOD(Phalcon_Mvc_Router, clear) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_property_zval(this_ptr, SL("_routes"), &_0);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the processed namespace name
 */
PHP_METHOD(Phalcon_Mvc_Router, getNamespaceName) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_namespace");

}

/**
 * Returns the processed module name
 */
PHP_METHOD(Phalcon_Mvc_Router, getModuleName) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_module");

}

/**
 * Returns the processed controller name
 */
PHP_METHOD(Phalcon_Mvc_Router, getControllerName) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_controller");

}

/**
 * Returns the processed action name
 */
PHP_METHOD(Phalcon_Mvc_Router, getActionName) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_action");

}

/**
 * Returns the processed parameters
 */
PHP_METHOD(Phalcon_Mvc_Router, getParams) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_params");

}

/**
 * Returns the route that matches the handled URI
 */
PHP_METHOD(Phalcon_Mvc_Router, getMatchedRoute) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_matchedRoute");

}

/**
 * Returns the sub expressions in the regular expression matched
 */
PHP_METHOD(Phalcon_Mvc_Router, getMatches) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_matches");

}

/**
 * Checks if the router matches any of the defined routes
 */
PHP_METHOD(Phalcon_Mvc_Router, wasMatched) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_wasMatched");

}

/**
 * Returns all the routes defined in the router
 */
PHP_METHOD(Phalcon_Mvc_Router, getRoutes) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_routes");

}

/**
 * Returns a route object by its id
 */
PHP_METHOD(Phalcon_Mvc_Router, getRouteById) {

	zend_string *_6;
	zend_ulong _5;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *id, id_sub, route, routeId, key, _0, _3, *_4, _1$$3, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&id_sub);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&routeId);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &id);



	ZEPHIR_OBS_VAR(&key);
	zephir_read_property(&_0, this_ptr, SL("_keyRouteIds"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&key, &_0, id, 0 TSRMLS_CC)) {
		zephir_read_property(&_1$$3, this_ptr, SL("_routes"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_2$$3, &_1$$3, &key, PH_NOISY | PH_READONLY, "phalcon/mvc/router.zep", 971 TSRMLS_CC);
		RETURN_CTOR(&_2$$3);
	}
	zephir_read_property(&_3, this_ptr, SL("_routes"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_3, 0, "phalcon/mvc/router.zep", 982);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_3), _5, _6, _4)
	{
		ZEPHIR_INIT_NVAR(&key);
		if (_6 != NULL) { 
			ZVAL_STR_COPY(&key, _6);
		} else {
			ZVAL_LONG(&key, _5);
		}
		ZEPHIR_INIT_NVAR(&route);
		ZVAL_COPY(&route, _4);
		ZEPHIR_CALL_METHOD(&routeId, &route, "getrouteid", NULL, 0);
		zephir_check_call_status();
		zephir_update_property_array(this_ptr, SL("_keyRouteIds"), &routeId, &key TSRMLS_CC);
		if (ZEPHIR_IS_EQUAL(&routeId, id)) {
			RETURN_CCTOR(&route);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&route);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_MM_BOOL(0);

}

/**
 * Returns a route object by its name
 */
PHP_METHOD(Phalcon_Mvc_Router, getRouteByName) {

	zend_string *_6;
	zend_ulong _5;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, route, routeName, key, _0, _3, *_4, _1$$3, _2$$3;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&routeName);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}


	ZEPHIR_OBS_VAR(&key);
	zephir_read_property(&_0, this_ptr, SL("_keyRouteNames"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&key, &_0, &name, 0 TSRMLS_CC)) {
		zephir_read_property(&_1$$3, this_ptr, SL("_routes"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_2$$3, &_1$$3, &key, PH_NOISY | PH_READONLY, "phalcon/mvc/router.zep", 993 TSRMLS_CC);
		RETURN_CTOR(&_2$$3);
	}
	zephir_read_property(&_3, this_ptr, SL("_routes"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_3, 0, "phalcon/mvc/router.zep", 1006);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_3), _5, _6, _4)
	{
		ZEPHIR_INIT_NVAR(&key);
		if (_6 != NULL) { 
			ZVAL_STR_COPY(&key, _6);
		} else {
			ZVAL_LONG(&key, _5);
		}
		ZEPHIR_INIT_NVAR(&route);
		ZVAL_COPY(&route, _4);
		ZEPHIR_CALL_METHOD(&routeName, &route, "getname", NULL, 0);
		zephir_check_call_status();
		if (!(ZEPHIR_IS_EMPTY(&routeName))) {
			zephir_update_property_array(this_ptr, SL("_keyRouteNames"), &routeName, &key TSRMLS_CC);
			if (ZEPHIR_IS_EQUAL(&routeName, &name)) {
				RETURN_CCTOR(&route);
			}
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&route);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_MM_BOOL(0);

}

/**
 * Returns whether controller name should not be mangled
 */
PHP_METHOD(Phalcon_Mvc_Router, isExactControllerName) {

	zval *this_ptr = getThis();


	RETURN_BOOL(1);

}

zend_object *zephir_init_properties_Phalcon_Mvc_Router(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _2, _4, _6, _1$$3, _3$$4, _5$$5, _7$$6;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$6);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("_keyRouteIds"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("_keyRouteIds"), &_1$$3);
		}
		zephir_read_property(&_2, this_ptr, SL("_keyRouteNames"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval(this_ptr, SL("_keyRouteNames"), &_3$$4);
		}
		zephir_read_property(&_4, this_ptr, SL("_defaultParams"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			array_init(&_5$$5);
			zephir_update_property_zval(this_ptr, SL("_defaultParams"), &_5$$5);
		}
		zephir_read_property(&_6, this_ptr, SL("_params"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_6) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_7$$6);
			array_init(&_7$$6);
			zephir_update_property_zval(this_ptr, SL("_params"), &_7$$6);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

