
extern zend_class_entry *phalcon_mvc_model_criteriainterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_CriteriaInterface);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_setmodelname, 0, 1, Phalcon\\Mvc\\Model\\CriteriaInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_setmodelname, 0, 1, IS_OBJECT, "Phalcon\\Mvc\\Model\\CriteriaInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, modelName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, modelName)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_getmodelname, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_getmodelname, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_bind, 0, 1, Phalcon\\Mvc\\Model\\CriteriaInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_bind, 0, 1, IS_OBJECT, "Phalcon\\Mvc\\Model\\CriteriaInterface", 0)
#endif
	ZEND_ARG_ARRAY_INFO(0, bindParams, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, merge, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, merge)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_bindtypes, 0, 1, Phalcon\\Mvc\\Model\\CriteriaInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_bindtypes, 0, 1, IS_OBJECT, "Phalcon\\Mvc\\Model\\CriteriaInterface", 0)
#endif
	ZEND_ARG_ARRAY_INFO(0, bindTypes, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_where, 0, 1, Phalcon\\Mvc\\Model\\CriteriaInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_where, 0, 1, IS_OBJECT, "Phalcon\\Mvc\\Model\\CriteriaInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, conditions, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, conditions)
#endif
	ZEND_ARG_INFO(0, bindParams)
	ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_conditions, 0, 1, Phalcon\\Mvc\\Model\\CriteriaInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_conditions, 0, 1, IS_OBJECT, "Phalcon\\Mvc\\Model\\CriteriaInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, conditions, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, conditions)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_orderby, 0, 1, Phalcon\\Mvc\\Model\\CriteriaInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_orderby, 0, 1, IS_OBJECT, "Phalcon\\Mvc\\Model\\CriteriaInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, orderColumns, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, orderColumns)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_limit, 0, 1, Phalcon\\Mvc\\Model\\CriteriaInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_limit, 0, 1, IS_OBJECT, "Phalcon\\Mvc\\Model\\CriteriaInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, limit, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, limit)
#endif
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_forupdate, 0, 0, Phalcon\\Mvc\\Model\\CriteriaInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_forupdate, 0, 0, IS_OBJECT, "Phalcon\\Mvc\\Model\\CriteriaInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, forUpdate, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, forUpdate)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_sharedlock, 0, 0, Phalcon\\Mvc\\Model\\CriteriaInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_sharedlock, 0, 0, IS_OBJECT, "Phalcon\\Mvc\\Model\\CriteriaInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, sharedLock, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, sharedLock)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_andwhere, 0, 1, Phalcon\\Mvc\\Model\\CriteriaInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_andwhere, 0, 1, IS_OBJECT, "Phalcon\\Mvc\\Model\\CriteriaInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, conditions, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, conditions)
#endif
	ZEND_ARG_INFO(0, bindParams)
	ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_orwhere, 0, 1, Phalcon\\Mvc\\Model\\CriteriaInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_orwhere, 0, 1, IS_OBJECT, "Phalcon\\Mvc\\Model\\CriteriaInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, conditions, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, conditions)
#endif
	ZEND_ARG_INFO(0, bindParams)
	ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_betweenwhere, 0, 3, Phalcon\\Mvc\\Model\\CriteriaInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_betweenwhere, 0, 3, IS_OBJECT, "Phalcon\\Mvc\\Model\\CriteriaInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, expr, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, expr)
#endif
	ZEND_ARG_INFO(0, minimum)
	ZEND_ARG_INFO(0, maximum)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_notbetweenwhere, 0, 3, Phalcon\\Mvc\\Model\\CriteriaInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_notbetweenwhere, 0, 3, IS_OBJECT, "Phalcon\\Mvc\\Model\\CriteriaInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, expr, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, expr)
#endif
	ZEND_ARG_INFO(0, minimum)
	ZEND_ARG_INFO(0, maximum)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_inwhere, 0, 2, Phalcon\\Mvc\\Model\\CriteriaInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_inwhere, 0, 2, IS_OBJECT, "Phalcon\\Mvc\\Model\\CriteriaInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, expr, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, expr)
#endif
	ZEND_ARG_ARRAY_INFO(0, values, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_notinwhere, 0, 2, Phalcon\\Mvc\\Model\\CriteriaInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_notinwhere, 0, 2, IS_OBJECT, "Phalcon\\Mvc\\Model\\CriteriaInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, expr, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, expr)
#endif
	ZEND_ARG_ARRAY_INFO(0, values, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_execute, 0, 0, Phalcon\\Mvc\\Model\\ResultsetInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_execute, 0, 0, IS_OBJECT, "Phalcon\\Mvc\\Model\\ResultsetInterface", 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_criteriainterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, setModelName, arginfo_phalcon_mvc_model_criteriainterface_setmodelname)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, getModelName, arginfo_phalcon_mvc_model_criteriainterface_getmodelname)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, bind, arginfo_phalcon_mvc_model_criteriainterface_bind)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, bindTypes, arginfo_phalcon_mvc_model_criteriainterface_bindtypes)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, where, arginfo_phalcon_mvc_model_criteriainterface_where)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, conditions, arginfo_phalcon_mvc_model_criteriainterface_conditions)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, orderBy, arginfo_phalcon_mvc_model_criteriainterface_orderby)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, limit, arginfo_phalcon_mvc_model_criteriainterface_limit)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, forUpdate, arginfo_phalcon_mvc_model_criteriainterface_forupdate)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, sharedLock, arginfo_phalcon_mvc_model_criteriainterface_sharedlock)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, andWhere, arginfo_phalcon_mvc_model_criteriainterface_andwhere)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, orWhere, arginfo_phalcon_mvc_model_criteriainterface_orwhere)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, betweenWhere, arginfo_phalcon_mvc_model_criteriainterface_betweenwhere)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, notBetweenWhere, arginfo_phalcon_mvc_model_criteriainterface_notbetweenwhere)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, inWhere, arginfo_phalcon_mvc_model_criteriainterface_inwhere)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, notInWhere, arginfo_phalcon_mvc_model_criteriainterface_notinwhere)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, getWhere, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, getConditions, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, getLimit, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, getOrderBy, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, getParams, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, execute, arginfo_phalcon_mvc_model_criteriainterface_execute)
	PHP_FE_END
};
