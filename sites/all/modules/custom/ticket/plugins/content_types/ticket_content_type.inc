<?php
// описываем плагин
$plugin = array(
'title' => t('Ticket get form content type plugin'),
'description' => t('Form for get ticket'),
'render callback' => 'ticket_content_type_render',
'edit form' => 'ticket_edit_form',
'category' => t('Custom panes'),
'single' => TRUE,
);


function ticket_content_type_render($subtype, $conf, $args, $context) {
  $block = new stdClass();
  $block->title = check_plain("Ticket form");
  $entity = entity_get_controller('ticket')->create();
  $form = drupal_get_form('ticket_form', $entity, $conf);
  $block->content = $form;
  return $block;
}
function ticket_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['admin'] = array(
    '#type' => 'textfield',
    '#title' => t('Url for admin'),
    '#default_value' => !empty($conf['admin']) ? $conf['admin'] : '',
  );

  $form['user'] = array(
    '#type' => 'textfield',
    '#title' => t('Url for user'),
    '#default_value' => !empty($conf['user']) ? $conf['user'] : '',
  );
  return $form;
}
function ticket_edit_form_submit($form, &$form_state) {

  foreach (element_children($form) as $key) {
    if (!empty($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

function ticket_form_ticket_form_alter(&$form, &$form_state) {
  $form['#submit'][] = 'ticket_form_handler';
}

function ticket_form_handler(&$form, &$form_state) {
  global $user;
  if (in_array('administrator', $user->roles)) {
    $form_state['redirect'] = $form_state['build_info']['args'][1]['admin'];
  } else {
    $form_state['redirect'] = $form_state['build_info']['args'][1]['user'];
  }
}