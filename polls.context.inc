<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function polls_context_default_contexts() {
  $export = array();
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'spaces-feature-poll';
  $context->description = 'context for space polls';
  $context->tag = 'lc';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'poll' => 'poll',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
    'path' => array(
      'values' => array(
        '*/poll/*' => '*/poll/*',
      ),
    ),
    'views' => array(
      'values' => array(
        'polls' => 'polls',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-recent_poll_comments-block' => array(
          'module' => 'views',
          'delta' => 'recent_poll_comments-block',
          'region' => 'right',
          'weight' => 0,
        ),
      ),
    ),
    'menu' => 'poll',
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('context for space polls');
  t('lc');

  $export['spaces-feature-poll'] = $context;
  return $export;
}
