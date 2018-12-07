<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Assets\Inline\Js;

use UnitTester;

/**
 * Class SetTypeCest
 *
 * @package Phalcon\Test\Unit\Assets\Inline\Js
 */
class SetTypeCest
{
    /**
     * Tests Phalcon\Assets\Inline\Js :: setType()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsInlineJsSetType(UnitTester $I)
    {
        $I->wantToTest("Assets\Inline\Js - setType()");
        $I->skipTest("Need implementation");
    }
}
