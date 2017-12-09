class CreateDisponilidadSalas < ActiveRecord::Migration[5.0]
  def change
    create_table :disponibilidad_salas do |t|
      t.integer :sala_id
      t.string :dia
      t.integer :periodo_id
      t.boolean :ocupado

      t.timestamps
    end
  end
end
