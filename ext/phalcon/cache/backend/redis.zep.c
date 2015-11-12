
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
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/hash.h"
#include "kernel/string.h"


/**
 * Phalcon\Cache\Backend\Redis
 *
 * Allows to cache output fragments, PHP data or raw data to a redis backend
 *
 * This adapter uses the special redis key "_PHCR" to store all the keys internally used by the adapter
 *
 *<code>
 *
 * // Cache data for 2 days
 * $frontCache = new \Phalcon\Cache\Frontend\Data(array(
 *    "lifetime" => 172800
 * ));
 *
 * //Create the Cache setting redis connection options
 * $cache = new Phalcon\Cache\Backend\Redis($frontCache, array(
 *		'host' => 'localhost',
 *		'port' => 6379,
 *		'auth' => 'foobared',
 *  	'persistent' => false
 * ));
 *
 * //Cache arbitrary data
 * $cache->save('my-data', array(1, 2, 3, 4, 5));
 *
 * //Get data
 * $data = $cache->get('my-data');
 *
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Cache_Backend_Redis) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Cache\\Backend, Redis, phalcon, cache_backend_redis, phalcon_cache_backend_ce, phalcon_cache_backend_redis_method_entry, 0);

	zend_declare_property_null(phalcon_cache_backend_redis_ce, SL("_redis"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_cache_backend_redis_ce TSRMLS_CC, 1, phalcon_cache_backendinterface_ce);
	return SUCCESS;

}

/**
 * Phalcon\Cache\Backend\Redis constructor
 *
 * @param	Phalcon\Cache\FrontendInterface frontend
 * @param	array options
 */
PHP_METHOD(Phalcon_Cache_Backend_Redis, __construct) {

	zend_bool _0, _2;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_9 = NULL;
	zval *frontend, *options = NULL, *_1, *_3, *_4$$4, *_5$$5, *_6$$6, *_7$$7, *_8$$9;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &frontend, &options);

	if (!options) {
		ZEPHIR_CPY_WRT(options, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(options);
	}


	if (Z_TYPE_P(options) != IS_ARRAY) {
		ZEPHIR_INIT_NVAR(options);
		array_init(options);
	}
	_0 = zephir_array_isset_string(options, SS("redis"));
	if (_0) {
		zephir_array_fetch_string(&_1, options, SL("redis"), PH_NOISY | PH_READONLY, "phalcon/cache/backend/redis.zep", 74 TSRMLS_CC);
		_0 = !(ZEPHIR_IS_EMPTY(_1));
	}
	_2 = _0;
	if (_2) {
		ZEPHIR_OBS_VAR(_3);
		zephir_array_fetch_string(&_3, options, SL("redis"), PH_NOISY, "phalcon/cache/backend/redis.zep", 74 TSRMLS_CC);
		_2 = Z_TYPE_P(_3) == IS_OBJECT;
	}
	if (_2) {
		zephir_array_fetch_string(&_4$$4, options, SL("redis"), PH_NOISY | PH_READONLY, "phalcon/cache/backend/redis.zep", 75 TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("_redis"), _4$$4 TSRMLS_CC);
	}
	if (!(zephir_array_isset_string(options, SS("host")))) {
		ZEPHIR_INIT_VAR(_5$$5);
		ZVAL_STRING(_5$$5, "127.0.0.1", 1);
		zephir_array_update_string(&options, SL("host"), &_5$$5, PH_COPY | PH_SEPARATE);
	}
	if (!(zephir_array_isset_string(options, SS("port")))) {
		ZEPHIR_INIT_VAR(_6$$6);
		ZVAL_LONG(_6$$6, 6379);
		zephir_array_update_string(&options, SL("port"), &_6$$6, PH_COPY | PH_SEPARATE);
	}
	if (!(zephir_array_isset_string(options, SS("index")))) {
		ZEPHIR_INIT_VAR(_7$$7);
		ZVAL_LONG(_7$$7, 0);
		zephir_array_update_string(&options, SL("index"), &_7$$7, PH_COPY | PH_SEPARATE);
	}
	if (!(zephir_array_isset_string(options, SS("persistent")))) {
		zephir_array_update_string(&options, SL("persistent"), &ZEPHIR_GLOBAL(global_false), PH_COPY | PH_SEPARATE);
	}
	if (!(zephir_array_isset_string(options, SS("statsKey")))) {
		ZEPHIR_INIT_VAR(_8$$9);
		ZVAL_STRING(_8$$9, "_PHCR", 1);
		zephir_array_update_string(&options, SL("statsKey"), &_8$$9, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_CALL_PARENT(NULL, phalcon_cache_backend_redis_ce, this_ptr, "__construct", &_9, 106, frontend, options);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Create internal connection to redis
 */
PHP_METHOD(Phalcon_Cache_Backend_Redis, _connect) {

	zend_bool _0, _1;
	zval *options = NULL, *redis = NULL, *persistent = NULL, *success = NULL, *host = NULL, *port = NULL, *auth = NULL, *index = NULL, *_2$$6, *_3$$6;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(options);
	zephir_read_property_this(&options, this_ptr, SL("_options"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(redis);
	object_init_ex(redis, zephir_get_internal_ce(SS("redis") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, redis, "__construct", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(host);
	_0 = !(zephir_array_isset_string_fetch(&host, options, SS("host"), 0 TSRMLS_CC));
	if (!(_0)) {
		ZEPHIR_OBS_VAR(port);
		_0 = !(zephir_array_isset_string_fetch(&port, options, SS("port"), 0 TSRMLS_CC));
	}
	_1 = _0;
	if (!(_1)) {
		ZEPHIR_OBS_VAR(persistent);
		_1 = !(zephir_array_isset_string_fetch(&persistent, options, SS("persistent"), 0 TSRMLS_CC));
	}
	if (_1) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options", "phalcon/cache/backend/redis.zep", 112);
		return;
	}
	if (zephir_is_true(persistent)) {
		ZEPHIR_CALL_METHOD(&success, redis, "pconnect", NULL, 0, host, port);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_METHOD(&success, redis, "connect", NULL, 0, host, port);
		zephir_check_call_status();
	}
	if (!(zephir_is_true(success))) {
		ZEPHIR_INIT_VAR(_2$$6);
		object_init_ex(_2$$6, phalcon_cache_exception_ce);
		ZEPHIR_INIT_VAR(_3$$6);
		ZEPHIR_CONCAT_SVSV(_3$$6, "Could not connect to the Redisd server ", host, ":", port);
		ZEPHIR_CALL_METHOD(NULL, _2$$6, "__construct", NULL, 9, _3$$6);
		zephir_check_call_status();
		zephir_throw_exception_debug(_2$$6, "phalcon/cache/backend/redis.zep", 122 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_OBS_VAR(auth);
	if (zephir_array_isset_string_fetch(&auth, options, SS("auth"), 0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(&success, redis, "auth", NULL, 0, auth);
		zephir_check_call_status();
		if (!(zephir_is_true(success))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Failed to authenticate with the Redisd server", "phalcon/cache/backend/redis.zep", 129);
			return;
		}
	}
	ZEPHIR_OBS_VAR(index);
	if (zephir_array_isset_string_fetch(&index, options, SS("index"), 0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(&success, redis, "select", NULL, 0, index);
		zephir_check_call_status();
		if (!(zephir_is_true(success))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Redisd server selected database failed", "phalcon/cache/backend/redis.zep", 137);
			return;
		}
	}
	zephir_update_property_this(this_ptr, SL("_redis"), redis TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns a cached content
 *
 * @param int|string keyName
 * @param   long lifetime
 * @return  mixed
 */
PHP_METHOD(Phalcon_Cache_Backend_Redis, get) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *keyName, *lifetime = NULL, *redis = NULL, *frontend = NULL, *prefix = NULL, *lastKey = NULL, *cachedContent = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &keyName, &lifetime);

	if (!lifetime) {
		lifetime = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_OBS_VAR(redis);
	zephir_read_property_this(&redis, this_ptr, SL("_redis"), PH_NOISY_CC);
	if (Z_TYPE_P(redis) != IS_OBJECT) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "_connect", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_OBS_NVAR(redis);
		zephir_read_property_this(&redis, this_ptr, SL("_redis"), PH_NOISY_CC);
	}
	ZEPHIR_OBS_VAR(frontend);
	zephir_read_property_this(&frontend, this_ptr, SL("_frontend"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(prefix);
	zephir_read_property_this(&prefix, this_ptr, SL("_prefix"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(lastKey);
	ZEPHIR_CONCAT_VV(lastKey, prefix, keyName);
	zephir_update_property_this(this_ptr, SL("_lastKey"), lastKey TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&cachedContent, redis, "get", NULL, 0, lastKey);
	zephir_check_call_status();
	if (!(zephir_is_true(cachedContent))) {
		RETURN_MM_NULL();
	}
	if (zephir_is_numeric(cachedContent)) {
		RETURN_CCTOR(cachedContent);
	}
	ZEPHIR_RETURN_CALL_METHOD(frontend, "afterretrieve", NULL, 0, cachedContent);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Stores cached content into the file backend and stops the frontend
 *
 * @param int|string keyName
 * @param string content
 * @param long lifetime
 * @param boolean stopBuffer
 */
PHP_METHOD(Phalcon_Cache_Backend_Redis, save) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool stopBuffer;
	zval *keyName = NULL, *content = NULL, *lifetime = NULL, *stopBuffer_param = NULL, *prefixedKey = NULL, *lastKey = NULL, *prefix = NULL, *frontend = NULL, *redis = NULL, *cachedContent = NULL, *preparedContent = NULL, *tmp = NULL, *tt1 = NULL, *success = NULL, *options = NULL, *specialKey = NULL, *isBuffering = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 4, &keyName, &content, &lifetime, &stopBuffer_param);

	if (!keyName) {
		keyName = ZEPHIR_GLOBAL(global_null);
	}
	if (!content) {
		content = ZEPHIR_GLOBAL(global_null);
	}
	if (!lifetime) {
		lifetime = ZEPHIR_GLOBAL(global_null);
	}
	if (!stopBuffer_param) {
		stopBuffer = 1;
	} else {
		stopBuffer = zephir_get_boolval(stopBuffer_param);
	}


	if (!(zephir_is_true(keyName))) {
		ZEPHIR_OBS_VAR(lastKey);
		zephir_read_property_this(&lastKey, this_ptr, SL("_lastKey"), PH_NOISY_CC);
		ZEPHIR_CPY_WRT(prefixedKey, lastKey);
	} else {
		ZEPHIR_OBS_VAR(prefix);
		zephir_read_property_this(&prefix, this_ptr, SL("_prefix"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(prefixedKey);
		ZEPHIR_CONCAT_VV(prefixedKey, prefix, keyName);
		ZEPHIR_CPY_WRT(lastKey, prefixedKey);
	}
	if (!(zephir_is_true(lastKey))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "The cache must be started first", "phalcon/cache/backend/redis.zep", 201);
		return;
	}
	ZEPHIR_OBS_VAR(frontend);
	zephir_read_property_this(&frontend, this_ptr, SL("_frontend"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(redis);
	zephir_read_property_this(&redis, this_ptr, SL("_redis"), PH_NOISY_CC);
	if (Z_TYPE_P(redis) != IS_OBJECT) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "_connect", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_OBS_NVAR(redis);
		zephir_read_property_this(&redis, this_ptr, SL("_redis"), PH_NOISY_CC);
	}
	if (!(zephir_is_true(content))) {
		ZEPHIR_CALL_METHOD(&cachedContent, frontend, "getcontent", NULL, 0);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(cachedContent, content);
	}
	if (!(zephir_is_numeric(cachedContent))) {
		ZEPHIR_CALL_METHOD(&preparedContent, frontend, "beforestore", NULL, 0, cachedContent);
		zephir_check_call_status();
	}
	if (!(zephir_is_true(lifetime))) {
		ZEPHIR_OBS_VAR(tmp);
		zephir_read_property_this(&tmp, this_ptr, SL("_lastLifetime"), PH_NOISY_CC);
		if (!(zephir_is_true(tmp))) {
			ZEPHIR_CALL_METHOD(&tt1, frontend, "getlifetime", NULL, 0);
			zephir_check_call_status();
		} else {
			ZEPHIR_CPY_WRT(tt1, tmp);
		}
	} else {
		ZEPHIR_CPY_WRT(tt1, lifetime);
	}
	if (zephir_is_numeric(cachedContent)) {
		ZEPHIR_CALL_METHOD(&success, redis, "set", NULL, 0, lastKey, cachedContent);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_METHOD(&success, redis, "set", NULL, 0, lastKey, preparedContent);
		zephir_check_call_status();
	}
	if (!(zephir_is_true(success))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Failed storing the data in redis", "phalcon/cache/backend/redis.zep", 247);
		return;
	}
	ZEPHIR_CALL_METHOD(NULL, redis, "settimeout", NULL, 0, lastKey, tt1);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(options);
	zephir_read_property_this(&options, this_ptr, SL("_options"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(specialKey);
	if (!(zephir_array_isset_string_fetch(&specialKey, options, SS("statsKey"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options", "phalcon/cache/backend/redis.zep", 255);
		return;
	}
	if (!ZEPHIR_IS_STRING(specialKey, "")) {
		ZEPHIR_CALL_METHOD(NULL, redis, "sadd", NULL, 0, specialKey, prefixedKey);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&isBuffering, frontend, "isbuffering", NULL, 0);
	zephir_check_call_status();
	if (stopBuffer == 1) {
		ZEPHIR_CALL_METHOD(NULL, frontend, "stop", NULL, 0);
		zephir_check_call_status();
	}
	if (ZEPHIR_IS_TRUE_IDENTICAL(isBuffering)) {
		zend_print_zval(cachedContent, 0);
	}
	if (0) {
		zephir_update_property_this(this_ptr, SL("_started"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(this_ptr, SL("_started"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Deletes a value from the cache by its key
 *
 * @param int|string keyName
 * @return boolean
 */
PHP_METHOD(Phalcon_Cache_Backend_Redis, delete) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *keyName, *redis = NULL, *prefix = NULL, *prefixedKey = NULL, *lastKey = NULL, *options = NULL, *specialKey = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &keyName);



	ZEPHIR_OBS_VAR(redis);
	zephir_read_property_this(&redis, this_ptr, SL("_redis"), PH_NOISY_CC);
	if (Z_TYPE_P(redis) != IS_OBJECT) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "_connect", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_OBS_NVAR(redis);
		zephir_read_property_this(&redis, this_ptr, SL("_redis"), PH_NOISY_CC);
	}
	ZEPHIR_OBS_VAR(prefix);
	zephir_read_property_this(&prefix, this_ptr, SL("_prefix"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(prefixedKey);
	ZEPHIR_CONCAT_VV(prefixedKey, prefix, keyName);
	ZEPHIR_CPY_WRT(lastKey, prefixedKey);
	ZEPHIR_OBS_VAR(options);
	zephir_read_property_this(&options, this_ptr, SL("_options"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(specialKey);
	if (!(zephir_array_isset_string_fetch(&specialKey, options, SS("statsKey"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options", "phalcon/cache/backend/redis.zep", 297);
		return;
	}
	if (!ZEPHIR_IS_STRING(specialKey, "")) {
		ZEPHIR_CALL_METHOD(NULL, redis, "srem", NULL, 0, specialKey, prefixedKey);
		zephir_check_call_status();
	}
	ZEPHIR_RETURN_CALL_METHOD(redis, "delete", NULL, 0, lastKey);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Query the existing cached keys
 *
 * @param string prefix
 * @return array
 */
PHP_METHOD(Phalcon_Cache_Backend_Redis, queryKeys) {

	zend_bool _3$$7;
	HashTable *_1$$6;
	HashPosition _0$$6;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *prefix = NULL, *redis = NULL, *options = NULL, *keys = NULL, *specialKey = NULL, *key = NULL, *value = NULL, **_2$$6;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &prefix);

	if (!prefix) {
		prefix = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_OBS_VAR(redis);
	zephir_read_property_this(&redis, this_ptr, SL("_redis"), PH_NOISY_CC);
	if (Z_TYPE_P(redis) != IS_OBJECT) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "_connect", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_OBS_NVAR(redis);
		zephir_read_property_this(&redis, this_ptr, SL("_redis"), PH_NOISY_CC);
	}
	ZEPHIR_OBS_VAR(options);
	zephir_read_property_this(&options, this_ptr, SL("_options"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(specialKey);
	if (!(zephir_array_isset_string_fetch(&specialKey, options, SS("statsKey"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options", "phalcon/cache/backend/redis.zep", 330);
		return;
	}
	if (ZEPHIR_IS_STRING(specialKey, "")) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Cached keys were disabled (options['statsKey'] == ''), you shouldn't use this function", "phalcon/cache/backend/redis.zep", 334);
		return;
	}
	ZEPHIR_CALL_METHOD(&keys, redis, "smembers", NULL, 0, specialKey);
	zephir_check_call_status();
	if (Z_TYPE_P(keys) == IS_ARRAY) {
		zephir_is_iterable(keys, &_1$$6, &_0$$6, 1, 0, "phalcon/cache/backend/redis.zep", 347);
		for (
		  ; zephir_hash_get_current_data_ex(_1$$6, (void**) &_2$$6, &_0$$6) == SUCCESS
		  ; zephir_hash_move_forward_ex(_1$$6, &_0$$6)
		) {
			ZEPHIR_GET_HMKEY(key, _1$$6, _0$$6);
			ZEPHIR_GET_HVALUE(value, _2$$6);
			_3$$7 = zephir_is_true(prefix);
			if (_3$$7) {
				_3$$7 = !(zephir_start_with(value, prefix, NULL));
			}
			if (_3$$7) {
				zephir_array_unset(&keys, key, PH_SEPARATE);
			}
		}
		zend_hash_destroy(_1$$6);
		FREE_HASHTABLE(_1$$6);
	}
	RETURN_CCTOR(keys);

}

/**
 * Checks if cache exists and it isn't expired
 *
 * @param string keyName
 * @param   long lifetime
 * @return boolean
 */
PHP_METHOD(Phalcon_Cache_Backend_Redis, exists) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *keyName = NULL, *lifetime = NULL, *lastKey = NULL, *redis = NULL, *prefix = NULL, *_0$$5 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &keyName, &lifetime);

	if (!keyName) {
		keyName = ZEPHIR_GLOBAL(global_null);
	}
	if (!lifetime) {
		lifetime = ZEPHIR_GLOBAL(global_null);
	}


	if (!(zephir_is_true(keyName))) {
		ZEPHIR_OBS_VAR(lastKey);
		zephir_read_property_this(&lastKey, this_ptr, SL("_lastKey"), PH_NOISY_CC);
	} else {
		ZEPHIR_OBS_VAR(prefix);
		zephir_read_property_this(&prefix, this_ptr, SL("_prefix"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(lastKey);
		ZEPHIR_CONCAT_VV(lastKey, prefix, keyName);
	}
	if (zephir_is_true(lastKey)) {
		ZEPHIR_OBS_VAR(redis);
		zephir_read_property_this(&redis, this_ptr, SL("_redis"), PH_NOISY_CC);
		if (Z_TYPE_P(redis) != IS_OBJECT) {
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "_connect", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_OBS_NVAR(redis);
			zephir_read_property_this(&redis, this_ptr, SL("_redis"), PH_NOISY_CC);
		}
		ZEPHIR_CALL_METHOD(&_0$$5, redis, "get", NULL, 0, lastKey);
		zephir_check_call_status();
		if (!(zephir_is_true(_0$$5))) {
			RETURN_MM_BOOL(0);
		}
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

/**
 * Increment of given $keyName by $value
 *
 * @param  string keyName
 * @param  long lifetime
 * @return long
 */
PHP_METHOD(Phalcon_Cache_Backend_Redis, increment) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *keyName = NULL, *value = NULL, *redis = NULL, *prefix = NULL, *lastKey = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &keyName, &value);

	if (!keyName) {
		keyName = ZEPHIR_GLOBAL(global_null);
	}
	if (!value) {
		ZEPHIR_CPY_WRT(value, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(value);
	}


	ZEPHIR_OBS_VAR(redis);
	zephir_read_property_this(&redis, this_ptr, SL("_redis"), PH_NOISY_CC);
	if (Z_TYPE_P(redis) != IS_OBJECT) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "_connect", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_OBS_NVAR(redis);
		zephir_read_property_this(&redis, this_ptr, SL("_redis"), PH_NOISY_CC);
	}
	if (!(zephir_is_true(keyName))) {
		ZEPHIR_OBS_VAR(lastKey);
		zephir_read_property_this(&lastKey, this_ptr, SL("_lastKey"), PH_NOISY_CC);
	} else {
		ZEPHIR_OBS_VAR(prefix);
		zephir_read_property_this(&prefix, this_ptr, SL("_prefix"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(lastKey);
		ZEPHIR_CONCAT_VV(lastKey, prefix, keyName);
		zephir_update_property_this(this_ptr, SL("_lastKey"), lastKey TSRMLS_CC);
	}
	if (!(zephir_is_true(value))) {
		ZEPHIR_INIT_NVAR(value);
		ZVAL_LONG(value, 1);
	}
	ZEPHIR_RETURN_CALL_METHOD(redis, "incrby", NULL, 0, lastKey, value);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Decrement of $keyName by given $value
 *
 * @param  string keyName
 * @param  long value
 * @return long
 */
PHP_METHOD(Phalcon_Cache_Backend_Redis, decrement) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *keyName = NULL, *value = NULL, *redis = NULL, *prefix = NULL, *lastKey = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &keyName, &value);

	if (!keyName) {
		keyName = ZEPHIR_GLOBAL(global_null);
	}
	if (!value) {
		ZEPHIR_CPY_WRT(value, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(value);
	}


	ZEPHIR_OBS_VAR(redis);
	zephir_read_property_this(&redis, this_ptr, SL("_redis"), PH_NOISY_CC);
	if (Z_TYPE_P(redis) != IS_OBJECT) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "_connect", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_OBS_NVAR(redis);
		zephir_read_property_this(&redis, this_ptr, SL("_redis"), PH_NOISY_CC);
	}
	if (!(zephir_is_true(keyName))) {
		ZEPHIR_OBS_VAR(lastKey);
		zephir_read_property_this(&lastKey, this_ptr, SL("_lastKey"), PH_NOISY_CC);
	} else {
		ZEPHIR_OBS_VAR(prefix);
		zephir_read_property_this(&prefix, this_ptr, SL("_prefix"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(lastKey);
		ZEPHIR_CONCAT_VV(lastKey, prefix, keyName);
		zephir_update_property_this(this_ptr, SL("_lastKey"), lastKey TSRMLS_CC);
	}
	if (!(zephir_is_true(value))) {
		ZEPHIR_INIT_NVAR(value);
		ZVAL_LONG(value, 1);
	}
	ZEPHIR_RETURN_CALL_METHOD(redis, "decrby", NULL, 0, lastKey, value);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Immediately invalidates all existing items.
 */
PHP_METHOD(Phalcon_Cache_Backend_Redis, flush) {

	HashTable *_1$$5;
	HashPosition _0$$5;
	zval *options = NULL, *specialKey = NULL, *redis = NULL, *keys = NULL, *key = NULL, *lastKey = NULL, **_2$$5;
	zephir_fcall_cache_entry *_3 = NULL, *_4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(options);
	zephir_read_property_this(&options, this_ptr, SL("_options"), PH_NOISY_CC);
	if (!(zephir_array_isset_string(options, SS("statsKey")))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options", "phalcon/cache/backend/redis.zep", 462);
		return;
	}
	ZEPHIR_OBS_VAR(specialKey);
	zephir_array_fetch_string(&specialKey, options, SL("statsKey"), PH_NOISY, "phalcon/cache/backend/redis.zep", 465 TSRMLS_CC);
	ZEPHIR_OBS_VAR(redis);
	zephir_read_property_this(&redis, this_ptr, SL("_redis"), PH_NOISY_CC);
	if (Z_TYPE_P(redis) != IS_OBJECT) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "_connect", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_OBS_NVAR(redis);
		zephir_read_property_this(&redis, this_ptr, SL("_redis"), PH_NOISY_CC);
	}
	ZEPHIR_CALL_METHOD(&keys, redis, "smembers", NULL, 0, specialKey);
	zephir_check_call_status();
	if (Z_TYPE_P(keys) == IS_ARRAY) {
		zephir_is_iterable(keys, &_1$$5, &_0$$5, 0, 0, "phalcon/cache/backend/redis.zep", 481);
		for (
		  ; zephir_hash_get_current_data_ex(_1$$5, (void**) &_2$$5, &_0$$5) == SUCCESS
		  ; zephir_hash_move_forward_ex(_1$$5, &_0$$5)
		) {
			ZEPHIR_GET_HVALUE(key, _2$$5);
			ZEPHIR_CPY_WRT(lastKey, key);
			ZEPHIR_CALL_METHOD(NULL, redis, "srem", &_3, 0, specialKey, key);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, redis, "delete", &_4, 0, lastKey);
			zephir_check_call_status();
		}
	}
	RETURN_MM_BOOL(1);

}

