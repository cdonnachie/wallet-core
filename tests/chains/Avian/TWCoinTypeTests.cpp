// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.
//
// This is a GENERATED FILE, changes made here MAY BE LOST.
// Generated one-time (codegen/bin/cointests)
//

#include "TestUtilities.h"
#include <TrustWalletCore/TWCoinTypeConfiguration.h>
#include <gtest/gtest.h>


TEST(TWAvianCoinType, TWCoinType) {
    auto symbol = WRAPS(TWCoinTypeConfigurationGetSymbol(TWCoinTypeAvian));
    auto txId = WRAPS(TWStringCreateWithUTF8Bytes("t123"));
    auto txUrl = WRAPS(TWCoinTypeConfigurationGetTransactionURL(TWCoinTypeAvian, txId.get()));
    auto accId = WRAPS(TWStringCreateWithUTF8Bytes("a12"));
    auto accUrl = WRAPS(TWCoinTypeConfigurationGetAccountURL(TWCoinTypeAvian, accId.get()));
    auto id = WRAPS(TWCoinTypeConfigurationGetID(TWCoinTypeAvian));
    auto name = WRAPS(TWCoinTypeConfigurationGetName(TWCoinTypeAvian));

    ASSERT_EQ(TWCoinTypeConfigurationGetDecimals(TWCoinTypeAvian), 8);
    ASSERT_EQ(TWBlockchainBitcoin, TWCoinTypeBlockchain(TWCoinTypeAvian));
    ASSERT_EQ(0x7a, TWCoinTypeP2shPrefix(TWCoinTypeAvian));
    ASSERT_EQ(0x0, TWCoinTypeStaticPrefix(TWCoinTypeAvian));
    assertStringsEqual(symbol, "AVN");
    assertStringsEqual(txUrl, "https://explorer.avn.network/tx/t123");
    assertStringsEqual(accUrl, "https://explorer.avn.network/address/a12");
    assertStringsEqual(id, "avian");
    assertStringsEqual(name, "Avian");
}
