#!/usr/bin/node

const request = require('request');
const movieId = process.argv[2];
const apiUrl = `https://swapi-api.alx-tools.com/api/films/${movieId}/`;

request(apiUrl, (error, response, body) => {
  const filmData = JSON.parse(body);
  filmData.characters.forEach(characterUrl => {
    request(characterUrl, (charError, charResponse, charBody) => {
      const characterData = JSON.parse(charBody);
      console.log(characterData.name);
    });
  });
});
