#!/usr/bin/env node
const request = require('request');

const movieId = process.argv[2];

request(`https://swapi.dev/api/films/${movieId}/`, { json: true }, (err, res, body) => {
  const characters = body.characters;

  const fetchName = url => new Promise(resolve => {
    request(url, { json: true }, (e, r, charData) => resolve(charData.name));
  });

  Promise.all(characters.map(fetchName)).then(names => {
    names.forEach(name => console.log(name));
  });
});
