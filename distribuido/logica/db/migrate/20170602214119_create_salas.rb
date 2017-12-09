class CreateSalas < ActiveRecord::Migration[5.0]
  def change
    create_table :salas do |t|
      t.integer :capacida
      t.decimal :latitud
      t.decimal :longitud
      t.string :nombre
      t.string :sigla
      t.string :tipo

      t.timestamps
    end
  end
end
