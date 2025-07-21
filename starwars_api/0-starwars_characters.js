#!/usr/bin/node

const request = require('request');
const movieId = process.argv[2];
const apiUrl = `https://swapi-api.alx-tools.com/api/films/${movieId}/`;

request(apiUrl, (error, response, body) => {
  const filmData = JSON.parse(body);
  const characterUrls = filmData.characters;

  function getCharacter(index) {
    if (index >= characterUrls.length) return;
    
    request(characterUrls[index], (err, res, charBody) => {
      const characterData = JSON.parse(charBody);
      console.log(characterData.name);
      getCharacter(index + 1);
    });
  }
  
  getCharacter(0);
});