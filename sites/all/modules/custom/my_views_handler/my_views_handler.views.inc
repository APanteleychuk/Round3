<?php
/**
 * Implements of hook_views_data().
 */
function my_views_handler_views_data() {
  $data = array();
  // Add Example group
  $data['example']['table']['group'] = t('Example');
  $data['example']['table']['join'] = array(
    // #global is a special flag which let's a table appear all the time.
    '#global' => array(),
  );
  // Add custom field
  $data['example']['custom_field'] = array(
    'title' => t('Custom Field 1'),
    'help' => t('Provides a custom field.'),
    'field' => array(
      'handler' => 'my_views_handler_custom_field',
    ),
  );
  // Add custom filter
  $data['node']['custom_filter'] = array(
    'group' => t('Custom'),
    'title' => t('My custom filter'),
    'help' => t('My custom filter'),
    'filter' => array(
      'handler' => 'my_views_handler_filter_my_custom_filter'
    ),
  );
  return $data;
}