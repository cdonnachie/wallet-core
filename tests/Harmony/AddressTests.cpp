// Copyright © 2017-2019 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "Harmony/Address.h"
#include "HexCoding.h"
#include "PrivateKey.h"

#include <gtest/gtest.h>

using namespace TW;
using namespace TW::Harmony;

TEST(HarmonyAddress, FromString) {
    const auto sender = Address("one1a50tun737ulcvwy0yvve0pvu5skq0kjargvhwe");
    const auto receiver = Address("one1tp7xdd9ewwnmyvws96au0e7e7mz6f8hjqr3g3p");

    ASSERT_EQ(sender.hexDump(), "ed1ebe4fd1f73f86388f231997859ca42c07da5d");
    ASSERT_EQ(receiver.hexDump(), "587c66b4b973a7b231d02ebbc7e7d9f6c5a49ef2");
}

TEST(HarmonyAddress, FromData) {
    const auto address = Address(parse_hex("0x587c66b4b973a7b231d02ebbc7e7d9f6c5a49ef2"));
    const auto address_2 = Address(parse_hex("0xed1ebe4fd1f73f86388f231997859ca42c07da5d"));
    ASSERT_EQ(address.string(), "one1tp7xdd9ewwnmyvws96au0e7e7mz6f8hjqr3g3p");
    ASSERT_EQ(address_2.string(), "one1a50tun737ulcvwy0yvve0pvu5skq0kjargvhwe");
}

TEST(HarmonyAddress, InvalidHarmonyAddress) {
    ASSERT_FALSE(Address::isValid("one1a50tun737ulcvwy0yvve0pe").first);
    ASSERT_FALSE(Address::isValid("oe1tp7xdd9ewwnmyvws96au0ee7e7mz6f8hjqr3g3p").first);
}

TEST(HarmonyAddress, FromPrivateKey) {
    const auto privateKey =
        PrivateKey(parse_hex("e2f88b4974ae763ca1c2db49218802c2e441293a09eaa9ab681779e05d1b7b94"));
    const auto publicKey = PublicKey(privateKey.getPublicKey(TWPublicKeyTypeSECP256k1Extended));
    const auto address = Address(publicKey);
    ASSERT_EQ(address.string(), "one1a50tun737ulcvwy0yvve0pvu5skq0kjargvhwe");
}