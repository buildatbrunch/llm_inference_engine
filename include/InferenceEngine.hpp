#ifndef INFERENCE_ENGINE_HPP
#define INFERENCE_ENGINE_HPP

#include <cstdint>
#include <string>
#include <vector>

using TokenId_t = int32_t;

class InferenceEngine {
public:
    virtual ~InferenceEngine() = default;

    virtual TokenId_t prefill(const std::string& prompt) = 0;
    virtual TokenId_t decode_step(const std::vector<TokenId_t>& token_history) = 0;
    virtual std::string tokenizer_decode(TokenId_t token_id) = 0;
};

#endif