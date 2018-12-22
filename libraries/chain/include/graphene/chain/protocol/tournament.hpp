/*
 * Copyright (c) 2015 Cryptonomex, Inc., and contributors.
 *
 * The MIT License
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#pragma once

#include <cassert>
#include <cstdint>
#include <string>

#include <fc/container/flat.hpp>
#include <fc/reflect/reflect.hpp>
#include <graphene/chain/protocol/asset.hpp>
#include <graphene/chain/protocol/base.hpp>

namespace graphene { namespace chain {

    enum class payout_type
    {
        prize_award,
        buyin_refund,
        rake_fee
    };

   struct tournament_payout_operation : public base_operation
   {
      struct fee_parameters_type {};

      asset fee;

      /// The account received payout
      account_id_type payout_account_id;

      /// The payout amount
      asset payout_amount;

      payout_type type;

      extensions_type extensions;

      account_id_type fee_payer()const { return payout_account_id; }
      share_type calculate_fee(const fee_parameters_type&)const { return 0; }
      void            validate()const {}
   };

} }

FC_REFLECT_ENUM(graphene::chain::payout_type,
                (prize_award)
                (buyin_refund)
                (rake_fee)
                )

FC_REFLECT( graphene::chain::tournament_payout_operation,
            (fee)
            (payout_account_id)
            (payout_amount)
            (type)
            (extensions))

FC_REFLECT( graphene::chain::tournament_payout_operation::fee_parameters_type,  )

