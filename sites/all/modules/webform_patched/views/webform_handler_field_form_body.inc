<?php

/**
* @file
* Views handler to display the content of a webform form.
*/

/**
 * Field handler to present the Webform form body to the user.
 */
class webform_handler_field_form_body extends views_handler_field {
  function construct() {
    parent::construct();
    $this->additional_fields['nid'] = 'nid';
  }

  function option_definition() {
    $options = parent::option_definition();
    $options['label'] = array('default' => 'Form', 'translatable' => TRUE);
    return $options;
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function render($values) {
    $node = node_load($values->{$this->aliases['nid']});

    if (node_access('view', $node)) {
      $form_body = drupal_render(node_view($node));
    }
    else {
      return;
    }

    return $form_body;
  }
}
