empty_data
~~~~~~~~~~

**データ型**: ``mixed`` **デフォルト**: ``array()`` , ``multiple`` または ``expanded`` の場合 ``''``
**type**: ``mixed`` **default**: ``array()`` if ``multiple`` or ``expanded``, ``''`` otherwise

このオプションは ``empty_value`` の選択肢が選ばれた時に、どのような値を返すかを決定します。

このオプションのデフォルト値はフィールドオプションによって異なります。:

* ``data_class`` が設定され、 ``required`` が ``true`` の場合、 ``new $data_class()``;
* ``data_class`` が設定され、 ``required`` が ``false`` の場合、 ``null``;
* ``data_class`` が設定されず、 ``compound`` が ``true`` の場合、 ``array()``;
* ``data_class`` が設定されず、 ``compound`` が ``false`` の場合、 ``null``.

しかし、必要に応じてこれを変更することができます。例えば、値が選択されていないとき ``gender`` フィールドを明示的に ``null`` に設定したいとすると、このようにできます。:
But you can customize this to your needs. For example, if you want the ``gender`` field to be
explicitly set to ``null`` when no value is selected, you can do it like this:

.. code-block:: php

    $builder->add('gender', 'choice', array(
        'choices' => array(
            'm' => 'Male',
            'f' => 'Female'
        ),
        'required'    => false,
        'empty_value' => 'Choose your gender',
        'empty_data'  => null
    ));

.. note::
    フォームクラス全体に ``empty_data`` オプションをセットしたい場合はクックブックの記事( :doc:`/cookbook/form/use_empty_data` )を参照してください。

.. 2014/01/11 yositani2002 ea93980be2825779064b1e365d07335604f0ee62
