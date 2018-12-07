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

namespace Phalcon\Test\Unit\Assets\Asset\Js;

use UnitTester;

/**
 * Class GetRealSourcePathCest
 *
 * @package Phalcon\Test\Unit\Assets\Asset\Js
 */
class GetRealSourcePathCest
{
    /**
     * Tests Phalcon\Assets\Asset\Js :: getRealSourcePath()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetJsGetRealSourcePath(UnitTester $I)
    {
        $I->wantToTest("Assets\Asset\Js - getRealSourcePath()");
        $I->skipTest("Need implementation");
    }
}
