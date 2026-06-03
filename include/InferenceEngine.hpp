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
    virtual TokenId_t decodeStep(const std::vector<TokenId_t>& tokenHistory) = 0;
    virtual std::string tokenizerDecode(TokenId_t tokenId) = 0;
};

#endif