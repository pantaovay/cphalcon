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

namespace Phalcon\Test\Unit\Assets\Exception;

use UnitTester;

/**
 * Class GetMessageCest
 *
 * @package Phalcon\Test\Unit\Assets\Exception
 */
class GetMessageCest
{
    /**
     * Tests Phalcon\Assets\Exception :: getMessage()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsExceptionGetMessage(UnitTester $I)
    {
        $I->wantToTest("Assets\Exception - getMessage()");
        $I->skipTest("Need implementation");
    }
}
