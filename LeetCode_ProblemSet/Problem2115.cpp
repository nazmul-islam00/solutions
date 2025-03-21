#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
   public:
    std::vector<std::string> findAllRecipes(
        std::vector<std::string>& recipes,
        std::vector<std::vector<std::string>>& ingredients,
        std::vector<std::string>& supplies) {
        std::unordered_set<std::string> suppliesSet(supplies.begin(), supplies.end());
        std::unordered_set<std::string> recipesSet(recipes.begin(), recipes.end());
        std::unordered_map<std::string, int> recipeIndexMap;
        std::vector<std::string> possibleRecipes;
        std::unordered_set<std::string> possible;
        possibleRecipes.reserve(recipes.size());

        for (int i = 0; i < recipes.size(); i++) {
            recipeIndexMap[recipes[i]] = i;
        }

        for (const std::string& recipe : recipes) {
            std::unordered_set<std::string> visited;
            visited.insert(recipe);

            if (isPossible(ingredients, recipeIndexMap, recipesSet, suppliesSet, visited, possible, recipe)) {
                possibleRecipes.push_back(recipe);
                possible.insert(recipe);
            }
        }

        return possibleRecipes;
    }

   private:
    bool isPossible(
        const std::vector<std::vector<std::string>>& ingredients,
        const std::unordered_map<std::string, int>& recipeIndexMap,
        const std::unordered_set<std::string>& recipesSet,
        std::unordered_set<std::string>& suppliesSet,
        std::unordered_set<std::string>& visited,
        std::unordered_set<std::string>& possible,
        const std::string& recipe) {
        for (const std::string& ingredient : ingredients[recipeIndexMap.find(recipe)->second]) {
            bool hasIngredient = suppliesSet.find(ingredient) != suppliesSet.end();
            if (hasIngredient) continue;

            bool isAnotherRecipe = recipesSet.find(ingredient) != recipesSet.end(); 
            if (!isAnotherRecipe) return false;

            if (possible.find(ingredient) != possible.end()) continue;

            if (visited.find(ingredient) != visited.end()) return false;
            visited.insert(ingredient);
 
            if (!isPossible(ingredients, recipeIndexMap, recipesSet, suppliesSet, visited, possible, ingredient)) return false;
            possible.insert(ingredient);
        }

        return true;
    }
};