/**
 * @param {*} obj
 * @param {*} classFunction
 * @return {boolean}
 */
var checkIfInstanceOf = function(obj, classFunction) {
    if(obj==null || typeof classFunction !=="function")return false;
    let comp = obj.__proto__;
    while(comp!==null){
        if(comp === classFunction.prototype){
            return true;
        }
        comp = comp.__proto__;
    }
    return false;
};

/**
 * checkIfInstanceOf(new Date(), Date); // true
 */