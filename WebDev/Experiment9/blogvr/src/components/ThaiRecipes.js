function ThaiRecipes() {
  const recipes = [
    {
      id: 6,
      title: 'Massaman Curry',
      date: 'March 14, 2022',
      image: require('./massaman.jpeg'),
      description: 'Massaman curry is a Thai dish featuring tender meat such as chicken or beef, simmered in a rich, coconut milk-based sauce, infused with aromatic spices like cinnamon, cardamom, and star anise, often served with potatoes and peanuts for a flavorful and comforting meal.',
      method: 'To prepare Massaman curry, start by heating oil in a large skillet over medium heat and sautéing 2-3 tablespoons of Massaman curry paste until fragrant. Add 1 pound of sliced chicken or beef, cooking until browned on all sides. Pour in one can of coconut milk, along with 1 cup of chicken or vegetable broth, then add 2-3 peeled and cubed potatoes, 1 chopped onion, 1 tablespoon of fish sauce, 1 tablespoon of tamarind paste, 2 tablespoons of brown sugar, and a handful of roasted peanuts. Simmer the curry uncovered for about 20-25 minutes or until the potatoes are tender and the sauce has thickened slightly. Adjust the seasoning to taste, adding more fish sauce or sugar if desired. Serve the Massaman curry hot over steamed jasmine rice, garnished with fresh cilantro and additional peanuts. Enjoy the aromatic and flavorful taste of this Thai classic!',
      comments: 23,
      likes:78,
      author: "Dhvani Thakkar", 
      authorId: 1
    },
  ];

  return recipes;
};


export default ThaiRecipes;