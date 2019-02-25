document.addEventListener("DOMContentLoaded", function() {
  var elems = document.querySelectorAll(".modal");
  var instances = M.Modal.init(elems, {});
});

document.addEventListener("DOMContentLoaded", function() {
  var elems = document.querySelectorAll(".tap-target");
  var instances = M.TapTarget.init(elems, {});
});

//add collapsible effect

document.addEventListener("DOMContentLoaded", function() {
  var elems = document.querySelectorAll(".collapsible");
  var instances = M.Collapsible.init(elems, {});
});

document.addEventListener("DOMContentLoaded", function() {
  var elems = document.querySelectorAll(".autocomplete");
  var instances = M.Autocomplete.init(elems, {
    data: {
      Strasbourg: "",
      Lyon: "",
      Paris: "",
      Bordeaux: "",
      Nancy: "",
      Metz: "",
      Montpellier: "",
      Toulouse: "",
      Caen: ""
    }
  });
});

jQuery(function() {
  var el = document.getElementById("listWidget");
  Sortable.create(el, {});
});

document.addEventListener("DOMContentLoaded", function() {
  var elems = document.querySelectorAll(".sidenav");
  var instances = M.Sidenav.init(elems, {});
});
