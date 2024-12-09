#include <benchmark/benchmark.h>

#include <random>

#include "strings/LetterCombination.h"

using namespace leetcode::strings;

std::string generateRandomString(){
    std::string res = "";
    std::string charset = "23456789";
    std::default_random_engine rng(std::random_device{}());
    std::uniform_int_distribution<size_t> dist(0, charset.size() - 1);
    for (int i = 0; i < 4; ++i){
        res.push_back(charset[dist(rng)]);
    }
    return res;
}

static auto letter_combination = LetterCombination<std::string>();

static void BM_LetterCombination(benchmark::State& state){
    std::string input = generateRandomString();
    for(auto _: state){
        auto ret = letter_combination.letterCombinations(input);
//        auto ret = letter_combination.letterCombinations("2345");
    }
}

static auto letter_combination_str_view = LetterCombination<std::string_view>();

static void BM_LetterCombinationStrView(benchmark::State& state){
    std::string input = generateRandomString();
    for(auto _: state){
        auto ret = letter_combination_str_view.letterCombinations(input);
//        auto ret = letter_combination_str_view.letterCombinations("2345");
    }
}

BENCHMARK(BM_LetterCombination);
BENCHMARK(BM_LetterCombinationStrView);

BENCHMARK_MAIN();