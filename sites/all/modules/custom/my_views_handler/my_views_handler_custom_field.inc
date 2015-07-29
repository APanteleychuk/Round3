<?php
/**
 * @file
 * Definition of example_handler_custom_field
 */
/**
 * Provides a custom views field.
 */
class my_views_handler_custom_field extends my_views_handler_field {
  function option_definition() {
    $options = parent::option_definition();
    return $options;
  }
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
  }
  function query() {
    // do nothing -- to override the parent query.
  }
  function render($data) {
    // If the devel module is enabled, you may view all of the
    // data provided by fields previously added in your view.
    // dpm($data);
    // Insert PHP code here, or display greeting.
    $output = t("Hello World!");
    return $output;
  }
}