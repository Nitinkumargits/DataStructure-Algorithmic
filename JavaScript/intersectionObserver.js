"use strict";

const obsCallback = function (entires, observer) {
  entires.forEach((entry) => console.log(entry));
};

const obsOptions = {
  root: null,
  thershold: 0.1,
};
const observer = new IntersectionObserver(obsCallback, obsOptions);

observer.observe(section1);
