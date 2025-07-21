#!/usr/bin/node
const axios = require('axios');

const movieId = process.argv[2];

axios.get(`https://swapi.dev/api/films/${movieId}/`)
  .then(response => {
    const characters = response.data.characters;
    return Promise.all(characters.map(url => axios.get(url).then(res => res.data.name)));
  })
  .then(names => {
    names.forEach(name => console.log(name));
  })
  .catch(err => {
    console.error('Error:', err.message);
  });
